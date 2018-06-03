/* Given an array A[] and a number x
find a pair whose sum is x*/

#include <iostream>
using namespace std ;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int sum_x(int arr[], int n, int x){
	int low = 0, high = n-1 ;
	while(low < high){
		if(arr[low]+arr[high] < x)
			low++ ;
		else if(arr[low]+arr[high] > x)
			high-- ;
		else if(arr[low]+arr[high] == x)
			return 1 ;
	}
	return -1 ;
}

int main(){
	int n,x ;
	int *A = NULL ;

	cout<<"\n enter size of array : " ;
	cin>>n ;

	A = new int[n] ;
	cout<<"\n enter array : ";
	for(int i = 0 ; i<n ; i++)
		cin>>A[i] ;

	quickSort(A, 0, n-1) ;
	/*for(int i = 0 ; i<n ; i++)
		cout<<A[i] ;
	*/
	cout<<"\n enter x : " ;
	cin>>x ;

	int flag = sum_x(A, n, x) ;

	if(flag == 1)
		cout<<"\nsum exist\n" ;
	else if(flag == -1)
		cout<<"\nsum doesn\'t exist\n" ;
	delete [] A ;
	return 0 ;
}
