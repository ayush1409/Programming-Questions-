/*
	input : given an array(n elements) each denoting size of different n arrays
			we have to merge these n arrays so that the cost of merging is minimum
			we can only merge two array at a time
	output : the cost of merging arrays
*/

#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int optimal_merge_cost(int arr[], int n){
	int merge_cost = 0 ;
	int new_element,l,r;
	list<int> seq ;
	sort(arr, arr+n) ;

	for(int i=0 ; i<n ; i++){
		seq.push_back(arr[i]) ;
	}

	while(seq.size() != 1) {
		for(auto it = seq.begin() ; it!=seq.end() ; it++)
			cout<<*it<<" " ;
		cout<<endl ;

		l = seq.front() ;
		seq.pop_front() ;
		r = seq.front() ;
		seq.pop_front() ;
		new_element = l+r ;
		seq.push_front(new_element) ;
		seq.sort() ;
	}
	merge_cost = seq.front() ;
	
	return merge_cost ;
}
int main(){
	int arr[] = {20,30,10,5,30} ;		// each element shows the size of different arrays
	int n = sizeof(arr)/sizeof(arr[0]) ;

	int cost = optimal_merge_cost(arr,n) ;

	cout<<"\noptimal merge cost : "<<cost<<endl ;
	return 0 ;
}
