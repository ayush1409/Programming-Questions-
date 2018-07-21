#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std ;

void sum_x(int arr[], int n, int x){
	unordered_map<int, int> umap;

	for(int i=0 ; i<n ; i++){
		if(umap.find(x - arr[i]) != umap.end())
			cout<<" ( "<<arr[i]<<", "<<x-arr[i]<<" )"<<endl ;
		umap[arr[i]] = i ;
	}

}
int main(){
	int arr[] = {2,3,4,5,8,9,10,11} ;
	int n = sizeof(arr)/sizeof(arr[0]) ;
	int x ;
	cin>>x ;
	sum_x(arr, n, x) ;
	return 0 ;
}
