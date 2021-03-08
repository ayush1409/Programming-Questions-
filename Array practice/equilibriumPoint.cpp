// Day 4
#include <iostream>
#include <bits/stdc++.h>
using namespace std ;

int equilibriumPoint(int arr[], int n){
	int sum = 0, leftSum = 0 ;
	
	for(int i = 0 ; i < n ;i++){
		sum += arr[i] ;
	}
	
	for(int i = 0 ; i < n ; i++){
		sum -= arr[i]; 
		
		if(leftSum == sum)
			return i ;
		
		leftSum += arr[i] ;
	}
	
	return -1 ;
}

int main(){
	
	int arr[] = {1,3,5,2,2} ;
	unsigned int n = sizeof(arr)/sizeof(arr[0]) ;
	
	int pos = equilibriumPoint(arr, n) ;
	
	if(pos == -1)
		cout<<"\nNo Equilibrium point" ;
	else
		cout<<"\nElement at position "<<pos+1<<" is the Equilibrium point" ;
	return 0 ;
}
