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
	};

bool compare(Car a, Car b){
	float x = a.location.first*a.location.first + a.location.second*a.location.second ;
	float y = b.location.first*b.location.first + b.location.second*b.location.second ;
	return x<y ;
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
