#include <iostream>
#include <list>
using namespace std ;

class Graph{
	int V ;
	list<int> *adj ;
public:
	Graph(int V ) ;
	void addEdge(int u,int v) ;
	void BFS(int s, int x) ;
};

Graph::Graph(int V){
	this -> V = V ;
	adj = new list<int>[V] ;
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v) ;
}

void Graph::BFS(int s, int x){
	int *level = new int[V] ;
	int *parent = new int[V] ;

	for(int i=0; i<V ; i++){
		level[i] = -1 ;
		parent[i] = -1 ;
	}
	list<int> queue ;

	level[s] = 0 ;
	queue.push_back(s) ;
	list<int>::iterator it ;
	cout<<endl ;

	while(!queue.empty()){
		s = queue.front() ;
		cout<<s<<" " ;
		queue.pop_front() ;
		for(it=adj[s].begin(); it!= adj[s].end() ; it++){
			if(level[*it] == -1){
				level[*it] = level[s] + 1 ;
				parent[*it] = s ;
				queue.push_back(*it) ;
			}
		}
	}
	bool node_found=false ;
	cout<<"\n at level "<<x<<" : " ;
	for(int i=0 ; i<V ; i++){
		if(level[i] == x){
			cout<<i<<" " ;
			node_found = true ;
		}

	}
	if(!node_found)
		cout<<"Zero node\n" ;
	cout<<endl ;
}

int main(){
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
	g.BFS(2, 1);
	return 0 ;
}
