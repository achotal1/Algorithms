#include <iostream>
#include <string>
using namespace std;
int main(){
    int n = 0;
    cin>>n;
    for(int i = 0; i<n; i++){
        string word;
        cin>>word;
        if(word.length() <= 10){
            cout<<word<<"\n";
        }else{
            string nword = word[0] + to_string(word.length() - 2) + word[word.length() - 1];
            cout<<nword<<"\n";
        }
    }
    return 0;
}