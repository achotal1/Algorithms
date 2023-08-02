#include <string>
#include <vector>
using namespace std;
std::vector<std::string> towerBuilder(unsigned nFloors) {
  vector<string> v(nFloors);
  string ans = "";
  int number = 1;
  for(int i = 1; i<nFloors; i++){
    number += 2;
  }
  for(int i = 0; i<number; i++){
    ans.push_back('*');
  }
  int front(0),back(number - 1);
  for(int i = nFloors - 1; i >= 0; i--){
    v[i] = ans;
    ans[front] = ' '; ans[back] = ' ';
    front++;back--;
  }
  return v;
}