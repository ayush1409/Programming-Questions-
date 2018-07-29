#include <iostream>
#include <vector>
using namespace std ;

void max_sum_subarray(int arr[], int n){
	int max_current = arr[0], max_global = arr[0] ;
	vector<int> subarray ;

	for(int i=1 ; i<n ; i++){
		if(arr[i] < arr[i] + max_current){
			max_current = arr[i] + max_current ;
			if(max_current >= max_global){
				max_global = max_current ;
				subarray.push_back(arr[i]) ;
			}
		}
		else if(arr[i] >= arr[i] + max_current){
			max_current = arr[i] ;
			if(max_current >= max_global){
				max_global = max_current ;
				subarray.clear() ;
				subarray.push_back(arr[i]) ;
			}
		}
	}

	cout<<"\n Max sum : "<<max_global<<"\n Max subarray : " ;
	for(auto it=subarray.begin() ; it != subarray.end() ; it++)
		cout<<*it<<" " ;

	cout<<endl ;
}
int main(){
	int arr[] = {1,-3,2,1,-1} ;
	int n = sizeof(arr)/sizeof(arr[0]) ;

	max_sum_subarray(arr,n) ;
	return 0 ;
}
