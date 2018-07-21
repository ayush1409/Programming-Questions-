// Map the array arr[0],arr[1],....,arr[n] to integers 0,1,2,....,n-1
/*
	input : 10, 40, 20
	output : 0, 2, 1
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std ;

void reduce_array(int arr[], int n){
	int temp[n] ;
	memcpy(temp, arr, n*sizeof(int)) ;

	sort(temp, temp+n) ;

	unordered_map<int, int> umap ;
/*
	for(int i=0; i<n ; i++)
		cout<<temp[i]<<" " ;
*/

	for(int i=0; i<n ; i++)
		umap[temp[i]] = i ;

	for(int i=0 ; i<n ; i++)
		arr[i] = umap[arr[i]] ;

}
int main(){
	int arr[] = {10, 40, 20} ;
	int n = sizeof(arr)/sizeof(arr[0]) ;
	reduce_array(arr,n) ;

	for(int i=0 ; i<n ; i++)
		cout<<arr[i]<<" " ;

	cout<<endl ;
	return 0 ;
}
