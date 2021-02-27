#include <iostream>
#include <bits/stdc++.h>
using namespace std ;

int main(){
	
	int arr[] = {1,4,5,4,4,6,2,3} ;
	int n = sizeof(arr)/sizeof(arr[0]);
	int pivot=4;
	int low=0, high=n-1, i=0 ;
	
	while(i <= high){
		if(arr[i] < pivot){
			swap(arr[i], arr[low]) ;
			low++ ;
			i++ ;
		}
		else if(arr[i] > pivot){
			swap(arr[i], arr[high]);
			high-- ;
		}
		else
			i++ ;
	}
	
	for(int j : arr){
			cout<<j<<" " ;
		}
	return 0 ;
}

