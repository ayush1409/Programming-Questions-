#include <iostream>
#include <bits/stdc++.h>
using namespace std ;

void swap(int a[], int i, int j){
		int temp = a[i] ;
		a[i] = a[j] ;
		a[j] = temp ;
	}
	
int main(){
	//assuming non zeros in array
	int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6} ;
	int n = sizeof(arr)/sizeof(arr[0]) ;
	
	int boundary=0 ;
	for(int j=1 ; j<n ; j++){
			if(arr[j]<0){
					swap(arr, boundary,j) ;
					boundary++ ;
				}
		}
		
	for(int i=0 ; i<n ; i++){
			cout<<arr[i]<<" " ; 
		}		
	return 0 ;
	}
