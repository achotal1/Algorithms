#include <iostream>
using namespace std;
int findfours(int num){
    int ans = 0;
    while(num > 0){
        if((num%10 - 4) == 0){
            ans++;
        }
        num = num/10;
    }
    return ans;
}
int main() {
    
	int T(0);
	cin>>T;
	for(int i = 0; i<T ; i++){
	    int number = 0; 
	    cin>>number;
	    cout<<findfours(number)<<'\n';
	}
	return 0;
}
-----------------------------------------------------------------------------------

// RLGL fizzbuzz
#include <iostream>
#include <vector>
using namespace std;
int findShotPeople(int num, int height){
    vector<int> v(num);
    int c = 0;
    for(int i = 0; i<num; i++){
        cin>>v[i];
    }
    for(auto a: v){
        if(a > height){
            c++;
        }
    }
    return c;
}
int main() {
	// your code goes here
	int t(0);
	cin>>t;
	for(int i = 0; i<t; i++){
	    int num = 0;
	    cin>>num;
	    int height = 0;
	    cin>>height;
	    cout<<findShotPeople(num,height)<<'\n';
	}
	return 0;
}
-------------------------------------------------------------------------------------------
// Play Piano
#include <iostream>
#include<string>
using namespace std;
string answer(string s){
    int c = 0;
    char store;
    string ans;
    for(int i = 0; i<s.length(); i++){
        if(i%2 == 0){
            store = s[i];
        }
        else{
            if(s[i] == store){
                ans = "no";
                return "no";
            }
        }
    }
   
    return "yes";
}
int main() {
	int T(0);
	cin>>T;
	for(int i = 0; i<T; i++){
	    string s;
	    cin>>s;
	    cout<<answer(s)<<'\n';
	}
	return 0;
}


