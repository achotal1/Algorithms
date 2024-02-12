#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string a,b;

    getline(cin, a);
    getline(cin, b);
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    long sumasciia(0), sumasciib(0);
    for(int i = 0; i<a.length(); i++){
        sumasciia += int(a[i]);
        sumasciib += int(b[i]);
    }
    if(sumasciia == sumasciib){
        cout<<"0\n";
    }else if(sumasciia > sumasciib){
        cout<<"1\n";
    }else{
        cout<<"-1\n";
    }

    return 0;
}