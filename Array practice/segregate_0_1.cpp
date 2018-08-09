/* 	Input array	= [0, 1, 0, 1, 0, 0, 1, 1, 1, 0]
	Output array = [0, 0, 0, 0, 0, 1, 1, 1, 1, 1]
*/
#include <iostream>
using namespace std ;

void swap(int *x, int *y){
	int temp = *x ;
	*x = *y ;
	*y = temp ;
}

void segregate(int arr[], int n){
	int start = 0, end = n-1 ;

	while(start < end){
		cout<<"\n start = "<<start<<"\tend = "<<end<<endl ;
		if(arr[start] == 0)
			start++ ;
		if(arr[end] == 1)
			end-- ;
		if(arr[start] == 1 && arr[end] == 0){
			swap(&arr[start], &arr[end]) ;
			start++ ; end-- ;
		}
	}
}

int main(){
	int arr[] = {0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0} ;
	int n = sizeof(arr)/sizeof(arr[0]) ;

	for(int i=0 ; i<n ; i++)
		cout<<arr[i]<<" " ;
	cout<<endl ;
	segregate(arr,n) ;
	for(int i=0 ; i<n ; i++)
		cout<<arr[i]<<" " ;
	cout<<endl ;
	return 0 ;
}
