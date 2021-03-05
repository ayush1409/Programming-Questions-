// Print all the combinations of 'r' length for a given length 'n' length array
// we are using Recurion with auxilary array
#include <iostream>
#include <bits/stdc++.h>
using namespace std ;

const int r = 3 ;
const int n = 7 ;

void printArray(int arr[], int len){
	for(int i = 0 ; i < len ; i++)
		cout<<arr[i]<<" " ;
	cout<<endl ;
}

void printCombs(int a[], int buffer[], int startIndex, int bufferIndex){
	
	// when we reach a valid combination
	if(bufferIndex == r){
		printArray(buffer, r) ;
		return ;
	}
	
	// when all the combinations are printed, terminate
	if(startIndex == n){
		return ;
	}
	
	for(int i = startIndex ; i < n ; i++){
		// place item into current bufferIndex
		buffer[bufferIndex] = a[i] ;
		
		// recurse to place next item on the next buffer index
		printCombs(a, buffer, i+1, bufferIndex + 1) ;
	}
	
}

int main(){
	
	int buffer[r] ;
	int a[] = {1,2,3,4,5,6,7} ;

	cout<<"Given Array : " ;
	for(int i = 0 ; i < n ; i++){
		cout<<a[i]<<" " ;
	}
	cout<<endl ;
	
	printCombs(a,buffer,0,0) ;	
	
	return 0 ;
}
