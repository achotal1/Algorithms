using namespace std;

#include <iostream>
#include <unordered_map>
#include <vector>

class MaxFruitCountOf2Types {
 public:
  static int findLength(const vector<char>& arr) {
    int maxLength = 0;
    int windowStart(0);
    unordered_map<char, int> charMap;

    for(int windowEnd = 0; windowEnd < arr.size(); windowEnd++){
      charMap[arr[windowEnd]]++;
      if(charMap.size() > 2){
        charMap[arr[windowStart]]--;
        if(charMap[arr[windowStart]] == 0){
          charMap.erase(arr[windowStart]);
        }
        windowStart++;
      }
      maxLength = max(maxLength,windowEnd - windowStart + 1);
    }
    return maxLength;
  }
};
