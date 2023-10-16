#include <iostream>
#include <string>
#include<vector>
using namespace std;
int main(){
    int n = 0;
    int k = 0;
    cin>>n;
    cin >> k;
    int count = 0;
    vector<int> list;
    int kscore = 0;
    for(int i = 0;i<n; i++){
        int v = 0;
        cin >> v;
        list.push_back(v);
        if(i == k - 1){
            kscore = v;
        }
    }
    for(int i = 0; i<list.size(); i++){
        if(list[i] > 0 && list[i] >= kscore){
            count++;
        }
    }
    cout<<count<<"\n";
    return 0;
}