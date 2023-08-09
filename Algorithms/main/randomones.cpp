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

#include <vector>
using namespace std;

int find_even_index (const vector <int> numbers) {
  int total_sum = 0;
  for(auto i: numbers){
    total_sum += i;
  }
  int leftsum = 0;
  int rightsum = 0;
  for(int i = 0; i<numbers.size(); i++){
    total_sum -= numbers[i];
    if(leftsum == total_sum){
      return i;
    }
    leftsum += numbers[i];
  }
  return -1;
  
}