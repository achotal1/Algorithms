#include <iostream>
#include <string>
using namespace std;
int main(){
    int n = 0;
    cin>>n;
    int count = 0;
    for(int i = 0; i<n; i++){
        int p(0),v(0),n(0);
        cin>>p>>v>>n;
        int sum = p+v+n;
        if(sum >= 2){
            count++;
        }
    }
    cout<<count<<"\n";
    return 0;
}