/*
Input: arr1[] = {11, 1, 13, 21, 3, 7}, arr2[] = {11, 3, 7, 1}
Output: arr2[] is a subset of arr1[]
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std ;

bool is_subset(int arr1[], int n1, int arr2[], int n2){
	unordered_set<int> arr1_set ;

	for(int i=0 ; i<n1 ; i++)
		arr1_set.insert(arr1[i]) ;

	for(int i=0; i<n2 ; i++){
		if(arr1_set.find(arr2[i]) == arr1_set.end())
			return false ;
	}

	return true ;

}

int main(){
	int arr1[] = {11, 1, 13, 21, 3, 7} ;
	int arr2[] = {11, 3, 7, 1} ;

	int n1 = sizeof(arr1)/sizeof(arr1[0]) ;
	int n2 = sizeof(arr2)/sizeof(arr2[0]) ;
	bool ans ;

	if(n1 >= n2)
		ans = is_subset(arr1, n1, arr2, n2) ;
	else
		ans = is_subset(arr2, n2, arr1, n1) ;

	if(ans)
		cout<<"YES"<<endl ;
	else
		cout<<"NO"<<endl ;

	return 0 ;
}

/*
NOTE : we cannot handle the case of duplicate elements
*/
