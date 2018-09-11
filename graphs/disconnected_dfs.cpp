#include <iostream>
#include <list>
using namespace std ;

class Graph{
	int V ;
	list<int> *adj ;
	void DFS_Util(int s, bool visited[]) ;
public:
	Graph(int V) ;
	void add_edge(int u,int v) ;
	void DFS() ;
};


Graph::Graph(int V){
	this-> V = V ;
	adj = new list<int>[V] ;
}

void Graph::add_edge(int u,int v){
	adj[u].push_back(v) ;
}

void Graph::DFS_Util(int s, bool visited[]){
	visited[s] = true ;
	cout<<s<<" " ;

	list<int>::iterator it ;

	for(it = adj[s].begin() ; it != adj[s].end() ; it++){
		if(!visited[*it])
			DFS_Util(*it, visited) ;
	}
}

void Graph::DFS(){
	bool *visited = new bool[V] ;
	for(int i=0 ; i<V ; i++)
		visited[i] = false ;

	for(int i=0 ; i<V ; i++){
		if(!visited[i])
			DFS_Util(i, visited) ;
	}
}

int main(){

	Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);
 
    cout << "Following is Depth First Traversaln";
    g.DFS();

    cout<<endl ;
	return 0 ;
}