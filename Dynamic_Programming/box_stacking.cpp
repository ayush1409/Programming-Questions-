#include <iostream>
using namespace std ;

bool if_placeble(int length_j,int width_j,int length_i,int width_i){
	if(length_j>length_i && width_j>width_i)
		return true ;
	return false ;
}

// function to calculate the max height
int max_height(int length[], int height[], int width[], int size){
	// create max_array, result array
	int max_array[size], result[size] ;
	for(int i=0 ; i<size ; i++){
		max_array[i] = height[i] ;
		result[i] = i ;
	}
	// calculate the max_height
	for(int i = 0 ; i<size ; i++){
		for(int j=0 ; j<i ; j++){
			if(max_array[i] < max_array[j]+height[i]){
				if(if_placeble(length[j], width[j], length[i], width[i])){
					max_array[i] = max_array[j] + height[i] ;
					result[i] = j ;
				}
			}
		}
	}

	int max_val = max_array[0] ;
	int max_index = 0 ;
	for(int i = 1 ; i<size ; i++){
		if(max_array[i] > max_val){
			max_val = max_array[i] ;
			max_index = i ;
		}
	}
	cout<<"\n Stack of Boxes "<<" \n (l,b,h)\n "<<length[max_index]<<" "<<width[max_index]<<" "<<height[max_index] ;
	int i = max_index ;
	while(i != result[i]){
		cout<<"\n "<<length[result[i]]<<" "<<width[result[i]]<<" "<<height[result[i]] ; ;
		i = result[i] ;
	}

	return max_val ;
}

int main(){
	// these are the possible instances of two boxes of dimensions (1 2 4) and (3 2 4)
	int length[] = {5,5,4,3,4,2} ;
	int height[] = {2,3,1,5,2,4} ;
	int width[] = {3,2,2,2,1,1} ;
	int size = sizeof(height)/sizeof(height[0]) ;
	int ans = max_height(length, height, width, size) ;
	cout<<"\n max height : "<<ans<<endl ;
	return 0 ;
}
