/*

The problem is to count all the possible paths from top left to bottom right of a 
MxN matrix with the constraints that from each cell you can either move to right or down.*/
using namespace std ;

int moves(int m,int n){
	if(m == 0)
		return 1 ;
	if(n == 0)
		return 1 ;
	return moves(m-1,n)+moves(m,n-1) ;
}

int main(){

	int m,n,T,result ;

	cin>>T ;
	for(int i=0 ; i<T ; i++){
		cin>>m>>n;

		result = moves(m-1,n-1) ;

		cout<<result<<endl ;
	}
	
	return 0 ;
}
