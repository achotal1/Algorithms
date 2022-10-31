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
