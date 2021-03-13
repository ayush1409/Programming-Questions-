// Find the minimum in sorted-rotated array
// Expected time = O(logn) and expected space = O(1) 

#include <iostream>
#include <bits/stdc++.h>
using namespace std ;

int minElement(int arr[], int n){
	int low = 0, high = n-1, right = arr[n-1], mid;
	
	while(low <= high){ 
		mid = low + (high - low)/2 ;
		if(arr[mid] < right && ((mid == 0) || arr[mid-1] > arr[mid])){
			return arr[mid] ;
		}
		else if(arr[mid] > right)
			low = mid + 1 ;
		else
			high = mid - 1 ;
	}
	
}

int main(){
	
	int arr[] = {6,7,8,9,1,2,3} ; 
	int n = sizeof(arr)/sizeof(arr[0]) ;
	
	cout<<"Array : " ;
	for(int i=0 ; i<n ; i++)
		cout<<arr[i]<<" " ;
		
	cout<<"\nMin Element : "<<minElement(arr,n) ;
	
	return 0 ;
}
