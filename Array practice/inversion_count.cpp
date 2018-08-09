/* count the number of inversions using divide and conquer*/
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std ;

int inversion_count_merge(int arr[], int l, int mid, int r){

	int n1 = mid-l+1 ;
	int n2 = r-mid ;
	int arr1[n1], arr2[n2] ;

	for(int i=0 ; i<n1 ; i++)
		arr1[i] = arr[l+i] ;
	for(int i=0 ; i<n2 ; i++)
		arr2[i] = arr[mid+i] ;

	/*for(int i=0 ; i<n1 ; i++)
		cout<<arr1[i]<<" " ;

	cout<<endl ;
	for(int i=0 ; i<n2 ; i++)
		cout<<arr2[i]<<" " ;
	cout<<endl ;
*/
	// sort both the arrays

	//sort(arr1, arr1+n1) ;
	//sort(arr2, arr2+n2) ;

	int i=0,j=0,k=0,count=0 ;

	while(i<n1 && j<n2){
		if(arr1[i]<arr2[j]){
			arr[k] = arr1[i] ;
			i++ ;
		}
		else if(arr1[i] >= arr2[j]){
			arr[k] = arr2[j] ;
			j++ ;
			count += n1-i+1 ;
		}
		k++ ;
	}
	while(i<n1){
		arr[k] = arr1[i] ;
		i++ ; k++ ;
	}
	while(j<n2){
		arr[k] = arr2[j] ;
		j++ ; k++ ;
	}

	return count ;
}

int inversion_count(int arr[], int l, int r){
	int count=0 ;
	if(l<r){
		int mid = l + (r-l)/2 ;

		inversion_count(arr,l,mid) ;
		inversion_count(arr,mid+1,r) ;
		count = inversion_count_merge(arr,l,mid,r) ;
		return count ;
	}
	return count ;
}

int main(){
	int arr[] = {3,1,4,5,1,2,0} ;
	int n = sizeof(arr)/sizeof(arr[0]) ;
	int count = inversion_count(arr,0,n-1) ;

	cout<<"\n "<<count<<" inversions"<<endl ;
	return 0 ;
}
