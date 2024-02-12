#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    vector<vector<int>> matrix(5, vector<int> (5, 0));
    int ans = 0;
    int row(0), column(0);
    for(int i = 0; i<5; i++){
        for(int j = 0; j<5; j++){
            cin>>matrix[i][j];
            if(matrix[i][j] == 1){
                row = i; column = j;
            }
        }
    }
    ans = abs(row - 2) + abs(column - 2); 
    cout<<ans<<"\n";
    return 0;

}