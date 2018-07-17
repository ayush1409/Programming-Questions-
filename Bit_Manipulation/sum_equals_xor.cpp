/* given n, find all 0<=i<=n for which (n+i) = (n^i) */
#include <iostream>
using namespace std ;

int find_all(int n){

	int unset_bits = 0 ;
	
	while(n){
		if((n&1) == 0)
			unset_bits++ ;
		n = n>>1 ;
	}
	return 1<<unset_bits ;
}
int main(){
	int n ;
	cout<<"\n Enter number : " ;
	cin>>n ;
	int x = find_all(n) ;
	cout<<"\n Answer : "<<x<<endl ;
	return 0 ;
}

/* Approach : use (a+b) = (a&b) + (a^b)
	find all (a&b) == 0 pairs
	which is equal to number of unset bits in either a or b
*/
