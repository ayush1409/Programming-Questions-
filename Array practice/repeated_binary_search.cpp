/*perform binary search in which elements may be repeated*/

#include <iostream>
using namespace std ;

int get_left_index(int arr[], int l, int r, int key){

	int mid ;
	while(r-l>1){
		mid = l + (r-l)/2 ;

		if(arr[mid] >= key)
			r = mid ;
		else
			l = mid ;
	}
	return r ;
}

int get_right_index(int arr[], int l, int r, int key){

	int mid ;
	while(r-l>1){
		mid = l + (r-l)/2 ;

		if(arr[mid] <= key)
			l = mid ;
		else
			r = mid ;
	}
	return l ;
} 

int main(){

	unsigned int n ;
	int key ;
	cin>>n>>key ;

	int *arr = new int[n] ;

	// the array must be sorted
	for(int i=0 ; i<n ; i++)
		cin>>arr[i] ;

	int left_cnt = get_left_index(arr,0,n-1,key) ;
	int right_cnt = get_right_index(arr,0,n-1,key) ;

	//cout<<"\nright_cnt  : "<<right_cnt<<endl ;
	//cout<<"\nleft_cnt : "<<left_cnt<<endl ;
	cout<<"\nthe elemet occurs at postions : " ;
	if(right_cnt-left_cnt){
		for(int i=left_cnt ; i<= right_cnt ; i++)
			cout<<i<<" " ;
		cout<<endl ;
	}
	else
		cout<<left_cnt<<endl ;

	cout<<endl ;
	return 0 ;
}