/*
 * 	input = [2,3,0,3,0,1,0]
 * 	output = [0,0,0,2,3,3,1]
 * */
#include <iostream>
#include <bits/stdc++.h>
using namespace std ;

int main(){
	
	int arr[] = {2,3,0,3,0,1,0};
	int n = sizeof(arr)/sizeof(arr[0]);
	int temp ;
	int boundary=0 ; 
	
	for(int i=0 ; i<n ; i++){
		if(arr[i] == 0){
			//swap a[i] and a[boundary]
			temp = arr[i] ;
			arr[i] = arr[boundary];
			arr[boundary]=temp;
			boundary++ ;
		}
	} 
	
	for(int i=0 ; i<n ; i++){
			cout<<arr[i]<<" " ;	 
		}
	return 0 ;
}
