#include <iostream>
#include <bits/stdc++.h>
using namespace std ;

int coinChange(int n, vector<int> &coins){
	
	vector<int> change(n+1, 0) ;
	
	change[0] = 1 ;
	
	for(unsigned int j = 0 ; j < coins.size() ; j++){
		
		for(unsigned int i = 0 ; i < change.size() ; i++){
			if(i+coins[j] > change.size() - 1)
				continue ;
			change[i + coins[j]] += change[i] ;
		}
	}
	
	return change[change.size() - 1] ;

}

int main(){
	
	int amount, numberOfChanges ;
	vector<int> coins ;
	coins.push_back(1) ;
	coins.push_back(2) ;
	coins.push_back(5) ;
	
	cout<<"Coins available : " ;
	for(int coin : coins)
		cout<<coin<<" " ;
	
	cout<<"Enter amount for change : " ;
	cin>>amount ;
	
	numberOfChanges = coinChange(amount, coins) ;
	cout<<"\nNumber of coin change possible : "<<numberOfChanges ;
	
	return 0 ;
}
