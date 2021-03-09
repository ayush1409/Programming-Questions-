#include <iostream>
#include <bits/stdc++.h>
using namespace std ;

template<typename T>
class QueueWithMax{
	private:
		queue<T> q ;		// to store the elements
		deque<T> maxq ;		// to retrieve the max value
		
	public:
		void push(const T &val){
				q.push(val) ;
				
				while(!maxq.empty() && maxq.back() < val)
					maxq.pop_back() ;
				
				maxq.push_back(val) ;
			}
		void pop(const T &val){
				if(maxq.front() == q.front())
					maxq.pop_front() ;
				q.pop();
			}
		
		T max(){
				if(!maxq.empty())
					return maxq.front() ;
			}
};

int main(){
	
	QueueWithMax<int> q ;
	
	int arr[] = {1,6,7,2,3,5,9,0} ;
	int n = sizeof(arr)/sizeof(arr[0]) ;
	
	for(int i = 0 ; i < n ; i++){
		q.push(arr[i]) ;			
		cout<<"Element pushed : "<<arr[i]<<", Max Element : "<<q.max()<<endl ;		
	}
	return 0 ;
}
