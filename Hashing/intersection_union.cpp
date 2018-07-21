#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std ;

void intersection_union(int arr1[], int n1, int arr2[], int n2){
	unordered_set<int> uset,intersection ;

	for(int i=0 ; i<n1 ; i++){
		uset.insert(arr1[i]) ;
	}

	for(int i=0 ; i<n2 ; i++){
		if(uset.find(arr2[i]) == uset.end())
			uset.insert(arr2[i]) ;
		else
			intersection.insert(arr2[i]) ;
	}

	cout<<"Union : " ;
	for(auto it=uset.begin() ; it!=uset.end() ; it++){
		cout<<*it<<" " ;
	}
	cout<<endl ;

	cout<<"Intersection : " ;
	for(auto it=intersection.begin() ; it!=intersection.end() ; it++){
		cout<<*it<<" " ;
	}
	cout<<endl ;
}
int main(){
	int arr1[] = {1,2,3,4,5,6,2,5,6} ;
	int n1 = sizeof(arr1)/sizeof(arr1[0]) ;

	int arr2[] = {1,2,3,4,11,19} ;
	int n2 = sizeof(arr2)/sizeof(arr2[0]) ;

	intersection_union(arr1,n1,arr2,n2) ;

	return 0 ;
}
