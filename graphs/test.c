#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	int n,i, fact=1 ;
	if(argc <=1)
		return -1 ;
	else{
		n = atoi(argv[1]) ;
		//b = atoi(argv[2]) ;

		//printf("%d%d",a,b) ;
		for(i=1 ; i<=n ; i++){
			fact = fact*i ;
		}
		printf("%d\n",fact);
	}
	return 0 ;
}  

