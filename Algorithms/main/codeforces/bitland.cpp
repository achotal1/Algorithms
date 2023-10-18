#include<iostream>
#include<string>
using namespace std;
int main(){
    int n = 0;
    cin>>n;
    string statement;
    int ans = 0;
    while(cin>>statement){
        if(statement[1] == '+'){
            ans++;
        }else{
            ans--;
        }
    }
    cout<<ans<<"\n";
    return 0;

}