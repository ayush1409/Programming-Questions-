/*Using DFS to detect the cycle in the graph*/
#include <iostream>
#include <list>
using namespace std ;

int count=0 ;
class Graph{
	int V ;
	list<int> *adj ;
public:
	Graph(int V) ;
	void addEdge(int u, int v) ;
	void dfs(int s) ;
	void dfs_util(int s, bool visited[], int parent[], int pre[], int post[]) ;
	bool check_cycle(int pre[], int post[]) ;
};

Graph::Graph(int V){
	this -> V = V ;
	adj = new list<int>[V] ;
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v) ;
}

void Graph::dfs_util(int s, bool visited[], int parent[], int pre[], int post[]){
	visited[s] = true ;
	pre[s] = count ;
	count++ ;
	cout<<s<<endl ;
	list<int>::iterator it;
	for(it=adj[s].begin() ; it != adj[s].end() ; it++){
		if(!visited[*it]){
			parent[*it] = s ;
			dfs_util(*it, visited, parent, pre, post) ;
			post[*it] = count ;
			count++ ;
		}
	}
	post[s]=count ;
}

// returns true if the graph has any back edge
bool Graph::check_cycle(int pre[], int post[]){
	list<int>::iterator it ;
	for(int i=0 ; i<V ; i++){
		for(it=adj[i].begin() ; it!=adj[i].end() ; it++){
			// check for back_edge
			if(pre[*it]<=pre[i] && post[*it] >= post[i]){
				return true ;
			}
		}
	}
	return false ;
}

void Graph::dfs(int s){
	bool *visited = new bool[V] ;
	int *parent = new int[V] ;
	int *pre = new int[V] ;
	int *post = new int[V] ;

	for(int i=0; i<V ; i++){
		visited[i] = false ;
		parent[i] = -1 ;
	}
	cout<<"\n DFS : "<<endl ;
	dfs_util(s,visited,parent,pre,post) ;

	for(int i=0 ; i<V ; i++){
		cout<<"\npre["<<i<<"] : "<<pre[i]<<"\tpost["<<i<<"] : "<<post[i]<<endl ;
	}

	if(check_cycle(pre,post))
		cout<<"\n Cycle exist."<<endl ;
	else
		cout<<"\n Not cyclic"<<endl ;
}

int main(){
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	g.dfs(0);

	return 0 ;
}
