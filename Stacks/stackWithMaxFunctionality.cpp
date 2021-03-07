#include <iostream>
#include <bits/stdc++.h>
using namespace std ;

template<typename T>
class MaxElementStack {
	
	private:
		stack<T> max_stack ;	// to store the max element
		stack<T> s ;			// actual stack
	
	public:
	void push(const T &val){
			s.push(val) ;
			
			if(max_stack.empty())
				max_stack.push(val) ;
			else if(max_stack.top() < val)
				max_stack.push(val) ;
		}
	

	void pop(){
		if(s.top() == max_stack.top()){
				s.pop() ;
				max_stack.pop() ;
			}
		else
			s.pop() ;
	}
	
	T max(){
		if(!max_stack.empty())
			return max_stack.top() ;
		}
};

int main(){
	
	MaxElementStack<int> s;
	
	int arr[] = {1,6,7,2,3,5,9,0} ;
	int n = sizeof(arr)/sizeof(arr[0]) ;
	
	for(int i = 0 ; i < n ; i++){
		s.push(arr[i]) ;			
		cout<<"Element pushed : "<<arr[i]<<", Max Element : "<<s.max()<<endl ;		
	}
	
	return 0 ;
}
