#include<iostream>
#include<string>
using namespace std;

int main(){
    int n(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        int y = 0;
        string number;
        cin>>number;
        int sum(0);
        for(int j = 0; j<number.length(); j++){
            if(number[j] == '0'){
                y = abs(10 - y);
                sum += y;
            }else{
                y = abs((number[i]-'0') - y);
                if(j != 0){
                    if(number[j-1] == number[j]){
                        sum ++;
                    }else{
                        y++;
                        sum += y;
                    }
                }else{
                    sum += y;
                }
            
            }
            
        }
        cout<<sum<<"\n";
    }

    return 0;
}