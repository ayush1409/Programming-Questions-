#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std ;

class complex{
	int real, img ;
public:
	complex(int _real, int _img){
		real = _real ;
		img = _img ;
	}
	int get_real() const {return real ;}
	int get_img() const {return img ;}
};

class my_comparator{
public:
	bool operator() (const complex& c1, const complex& c2){
		int l1 = sqrt(pow(c1.get_real(),2) + pow(c1.get_img(),2)) ;
		int l2 = sqrt(pow(c2.get_real(),2) + pow(c2.get_img(),2)) ;
		return l1 > l2 ;
	}
};

int main(){

	priority_queue<complex, vector<complex>, my_comparator> pq ;
	pq.push(complex(1,2)) ;
	pq.push(complex(0,1)) ;
	pq.push(complex(1,0)) ;
	pq.push(complex(0,0)) ;

	complex c ;/*
	while(!pq.empty()){
		c = pq.top()
		cout<<c.get_real()" +"<<c.get_img()<<"j"<<endl ;
		pq.pop() ;
	}*/
	return 0 ;
}
