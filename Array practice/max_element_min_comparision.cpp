/* get the maximum element by doing minimum comparision */
/* HINT : use divide and conquer*/
#include <iostream>
using namespace std ;

int max_element(int arr[], int l, int r){
	int x,y ;
	if(l<r){
		int mid = l + (r-l)/2 ;
		x = max_element(arr,l,mid) ;
		y = max_element(arr,mid+1,r) ;
		return max(x,y) ;
	}
	return arr[l] ;
}

int main(){
	int arr[] = {3,4,2,1,5,99} ;
	int n = sizeof(arr)/sizeof(arr[0]) ;

	int maximum = max_element(arr,0,n-1) ;
	cout<<"\n maximum : "<<maximum<<endl ;
	return 0 ;
}
