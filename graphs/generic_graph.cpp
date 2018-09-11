#include <iostream>
#include <vector>
#include <list>
using namespace std ; 

template<class T>
class graph{
	vector<list<T> > vectorList ;
public:
	void createGraph(int n, T*) ;
	bool addEdge(T,T) ;
	//bool removeEdge(T,T) ;
	void printOutgoing() ;
	//void printIncoming() ;
};	

template<class T>
void graph<T>:: createGraph(int n, T vertex[]){
	vectorList.resize(n) ;
	int arrayIndex = 0 ;

	for(typename vector<list<T> >:: iterator vectoriterator = vectorList.begin() ;
			vectoriterator != vectorList.end() ;
			vectoriterator++, arrayIndex++){

		(*vectoriterator).push_back(vertex[arrayIndex]) ;
	}
}

template<class T>
bool graph<T>:: addEdge(T source, T destination){

	bool foundvertex = false ;
	
	for(typename vector<list<T> >:: iterator vectoriterator = vectorList.begin() ; 
			vectoriterator != vectorList.end() ;
			vectoriterator++){

		typename list<T>:: iterator listiterator ;

		if((*listiterator) == source){
			listiterator++ ;

			for(; listiterator != (*vectoriterator).end() ; listiterator++){
				if((*listiterator) == destination){
					foundvertex = true ;
					break ;
				}
			}

	 		if(foundvertex == false){
				(*vectoriterator).push_back(destination) ;
				return true ;
			}
			else
				return false ;
		} 
	}
}

template<class T>
void graph<T>:: printOutgoing(){
	for(typename vector<list<T> >:: iterator vectoriterator = vectorList.begin(); 
			vectoriterator != vectorList.end() ; 
			vectoriterator){
		typename list<T>::iterator listiterator = (*vectoriterator).begin() ;

		cout<<(*listiterator)<<" : " ;
		listiterator++ ;

		for(; listiterator != (*vectoriterator).end() ; listiterator++){
			cout<<(*listiterator)<<" " ;
		}
		cout<<endl ;
	}
}

int main(){
	char vertex[] = {'A', 'B', 'C', 'D', 'E'} ;
	int total_vertex = sizeof(vertex)/sizeof(vertex[0]) ;
	//int total_edges = 5 ;
	char x,y ;

	graph<char> g ;
	
	g.createGraph(total_verte,x vertex) ;

	//cout<<"Enter number of edges : " ;
	//cin>>total_edges ;
	//cout<<"\n enter the node squences for each edge : "<<endl ;
	/*
	for(int i=0 ; i<total_edges ; i++){
		cin>>x>>y ;
		g.addEdge(x,y) ;
	}
	*/

	g.addEdge('A','B');
	g.addEdge('A','C');
	g.addEdge('C','A');
	g.addEdge('C','D');
	g.addEdge('C','B');
	g.addEdge('D','B');

	g.printOutgoing() ;

	return 0 ;
}