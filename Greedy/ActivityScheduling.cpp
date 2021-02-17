#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std ;

bool compare(pair<int, int> a, pair<int, int> b){
		// sorting by finish time
		return a.second < b.second ;
	}

int main(){
	
	int n,t,start,end ;
	cin>>t ;
	
	while(t--){
			cin>>n ;

			// activity(start, end)
			vector< pair<int, int> > activity(n) ;
			
			for(int i=0 ; i<n ; i++){
				cin>>start>>end ;
				activity[i].first = start ;
				activity[i].second = end ;
			}
			
			
			sort(activity.begin(), activity.end(), compare) ;
			
//			for(auto x : activity)
//				cout<<"\n (start : "<<x.first<<" , Finish : "<<x.second<<")" ;

			vector<pair<int, int> > scheduled_activities ;
			scheduled_activities.push_back(activity[0]) ;
			int last_finish = activity[0].second ;
			
			for(auto it=activity.begin()+1 ; it != activity.end() ; it++){
				if((*it).first >= last_finish){
						scheduled_activities.push_back(*it) ;
						last_finish = (*it).second ;
					}
			}
			
			cout<<"Scheduled activities: " ;
			for(auto x: scheduled_activities){
					cout<<"\n (start : "<<x.first<<" , Finish : "<<x.second<<")" ;
				}
			cout<<endl ;
			
				
		}
	return 0 ;
}
