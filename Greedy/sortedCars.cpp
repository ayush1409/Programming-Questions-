#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
#include <math.h>
using namespace std ;

class Car{
		public:
			//string name ;
			pair<int,int> location ;
		//Car(int x, int y){
		//		this -> location = make_pair(x,y) ;
		//	}
			
		int distance(){
			int x,y ;
			x = (this -> location).first ;
			y = (this -> location).second ;
				return x*x + y*y ;
			}
	};

bool compare(Car a, Car b){
	return a.distance() < b.distance() ;
}

int main(){
	
	int t,x,y,n ;
	
	cin>>t ;
	while(t--){
		cin>>n ;
		vector<Car> cars(n) ;
		//cars.reserve(n) ;
		
		for(int i=0 ; i<n ; i++){
			cin>>x>>y ;
			cars[i].location = make_pair(x,y) ;
		}
		
//		for(auto car : cars)
//			cout<<"\nlocation : ("<<car.location.first<<", "<<car.location.second<<")" ;
		
		sort(cars.begin(), cars.end(), compare) ;
		
		for(auto car : cars)
			cout<<"\nlocation : ("<<car.location.first<<", "<<car.location.second<<")";

	}

	
	return 0 ;
}
