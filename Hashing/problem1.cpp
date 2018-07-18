/*
Input:
"Chennai" -> "Banglore"
"Bombay" -> "Delhi"
"Goa"    -> "Chennai"
"Delhi"  -> "Goa"

Output:
Bombay->Delhi, Delhi->Goa, Goa->Chennai, Chennai->Banglore,
*/
#include <iostream>
#include <map>
#include <string>
using namespace std;

void print_order(map<string, string> data){

	// create reverse map
	map<string, string> rev_map ;
	map<string, string>::iterator it ;
	string start ;

	for(it=data.begin(); it!=data.end(); it++)
		rev_map[it->second] = it->first ;

	for(it=data.begin() ; it!=data.end() ; it++){
		if(rev_map.find(it->first) == rev_map.end()){
			start = it->first ;
			break ;
		}
	}

	if(start.empty()){
		cout<<"Invalid input!"<<endl ;
		return ;
	}

	it = data.find(start) ;
	while(it != data.end()){
		cout<<it->first<<"->"<<it->second<<" " ;
		it = data.find(it->second) ;
	}
	cout<<endl ;
}
int main(){
	map<string, string> data ;

	data["Chennai"] = "Banglore";
    data["Bombay"] = "Delhi";
    data["Goa"] = "Chennai";
    data["Delhi"] = "Goa";

	print_order(data) ;

	return 0 ;
}
/*
	Approach :
	// create a map
	// create its reverse map
	// find key that doen't exist in reverse map that will be the starting point
*/
