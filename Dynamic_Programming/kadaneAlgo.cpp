#include <iostream>
#include <bits/stdc++.h>
using namespace std ;

int maxSubarraySum(int arr[], int n){        
	int result=arr[0], maxSum = arr[0] ;
    
	for(int i=1 ; i<n ; i++){
		maxSum = max(arr[i], arr[i]+maxSum) ;
        result = max(result, maxSum) ;
    }
    return result ;
}

int main(){
	int arr[] = {-1,-2,-3,-4} ;
	int n = sizeof(arr)/sizeof(arr[0]) ;
	
	cout<<"Max Subarry Sum : "<<maxSubarraySum(arr,n) ;
	return 0 ;
}
