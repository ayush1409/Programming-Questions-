/*
	input : array say [0,-1,2,-3,1] and given 'x'
	output : 	find the triplet whose sum is equals to 'x'
				like (0,-3,1)
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std ;

void triplet_sum_x(int ar[], int n, int x){
	int reduced_sum,ele ;

	unordered_map<int,int> umap ;

	for(int i=0 ; i<n ; i++){
		ele = ar[i] ;
		reduced_sum = x-ele ;
		// find a pair whose sum is (x - ele)
		for(int j=0 ; j<n ; j++){
			if(umap.find(reduced_sum - ar[j]) != umap.end())
				cout<<"( "<<ele<<", "<<ar[j]<<", "<<reduced_sum-ar[j]<<" )"<<endl ;
			umap[ar[j]] = j ;
		}
	}
}

int main(){
	int ar[] = {0,-1,2,-3,1} ;
	int n = sizeof(ar)/sizeof(ar[0]) ;
	int x=-2 ;

	triplet_sum_x(ar,n,x) ;
	return 0 ;
}
