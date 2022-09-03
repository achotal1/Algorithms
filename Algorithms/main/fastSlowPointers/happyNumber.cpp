/*
A Happy Number is a number whose each digit square and sum will once equal to 1. 
Otherwise it will get caught in a loop getting the same number again.  
Ex. 12 = 1^2 + 2^2 = 5 
         5^2 = 25 
         and you keep going on until you find a loop or 1. 
This solution has been done via Unordered Map and not fast and slow pointers.
*/

using namespace std;

#include <iostream>
#include <unordered_map>

class HappyNumber {
 private:
  static int calculateSquare(int num){
    int sum(0);
    while(num/10 != 0){
      sum += (num%10) * (num%10);
      num = num/10;
    }
    sum += num*num;
    return sum;
  }
 public:
  static bool find(int num) {
    unordered_map<int,int> map;
    while(num != 1){
      num = calculateSquare(num);
      map[num]++;
      if(map[num]>1){
        return false;
      }
    }
    return true;
  }
};


int main(int argc, char* argv[]) {
  cout << HappyNumber::find(23) << endl;
  cout << HappyNumber::find(12) << endl;
}
