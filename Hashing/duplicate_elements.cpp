#include <iostream>
#include <bits/stdc++.h>
using namespace std ;

void print_duplicate(int arr[], int n){
	unordered_set<int> inset, duplicate ;

	for(int i=0; i<n ; i++){
		if(inset.find(arr[i]) == inset.end())
			inset.insert(arr[i]) ;
		else
			duplicate.insert(arr[i]) ;
	}

	cout<<"Duplicate elements : " ;

	for(auto it=duplicate.begin() ; it != duplicate.end() ; it++){
		cout<<*it<<" " ;
	}
	cout<<endl ;
}
int main(){
	int arr[] = {1,2,3,4,5,6,2,5,6} ;
	int n = sizeof(arr)/sizeof(arr[0]) ;

	print_duplicate(arr,n) ;
	return 0 ;
}
