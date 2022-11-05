#include <iostream>
#include<unordered_map>
using namespace std;

int main() {
	int T = 0;
	cin>>T;
	
	while(T--){
	    unordered_map<char,int> map;
	    string S; int count(0);
	    cin>>S;
	    for(int i = 0; i<S.length(); i++){
	        map[S[i]]++;
	    }
	    for(auto a: map){
	       
	        if(a.second == 1){
	            count += 1;
	        }
	        else{
	            count += a.second - (a.second/2);
	        }
	    }
	    cout<<count<<'\n';
	    
	}
	
	return 0;
}
