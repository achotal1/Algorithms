#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int main(){
    int m(0), n(0);
    cin>>m>>n;
    int area = m*n;
    int ans = floor(area/2);

    cout<<ans<<"\n";
    return 0;

}