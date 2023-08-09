#include <string>
#include<unordered_map>
using namespace std;
std::string duplicate_encoder(const std::string& word){
  unordered_map<char,int> map;
  string ans;
  for(auto i: word){
    map[tolower(i)]++;
  }
  for(auto i: word){
    cout<<i<<"  "<<map[i]<<endl;
    if(map[(tolower(i))] > 1){
      ans += ')';
    }else if(map[(tolower(i))] == 1){
      ans += '(';
    }
  }
  return ans;
}