#include <iostream>
#include <bits/stdc++.h> 
using namespace std ;

bool checkAnagrams(string &s1, string &s2){
	
	if(s1.size() != s2.size())
		return false ;
	
	//s1 = s1.tolower() ;
	//s2 = s2.tolower() ;
	
	vector<int> letters(256) ;
	
	for(unsigned int i = 0 ; i<s1.size() ; i++){
		letters[s1[i]]++ ;	
	}
	
	for(unsigned int i = 0 ; i<s1.size() ; i++){
		letters[s1[i]]-- ;	
	}
	
	for(int letter : letters){
		if(letter != 0)
			return false ;
	} 
	
	return true ;
}
int main(){
	string s1 = "abba" ;
	string s2 = "bAAb" ;
	
	cout<<"String 1: "<<s1<<", String 2: "<<s2 ;
	transform(s1.begin(), s1.end(), s1.begin(), ::tolower) ;
	transform(s2.begin(), s2.end(), s2.begin(), ::tolower) ;
	
	
	if(checkAnagrams(s1, s2))
		cout<<"\nStrings are anagram" ;
	else
		cout<<"\nStrings are not anagram" ;

	return 0 ;
}
