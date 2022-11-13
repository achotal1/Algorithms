/*
Example 1:

Input: String="oidbcaf", Pattern="abc"
Output: true
Explanation: The string contains "bca" which is a permutation of the given pattern.
Example 2:

Input: String="odicf", Pattern="dc"
Output: false
Explanation: No permutation of the pattern is present in the given string as a substring.
*/

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
class StringPermutation {
 public:
  static bool findPermutation(const string &str, const string &pattern) {
    // TODO: Write your code here
    unordered_map<char,int> patternMap;
    unordered_map<char,int> strMap;
    for(int i = 0; i< pattern.length(); i++){
      patternMap[pattern[i]]++;
    }
    int size = patternMap.size();
    int windowStart = 0;
    for(int windowEnd = 0; windowEnd < str.length(); windowEnd++){
      strMap[str[windowEnd]]++;
      
      if(patternMap.find(str[windowEnd]) == patternMap.end() && strMap[str[windowEnd]] > patternMap[str[windowEnd]]){
        while(windowStart != windowEnd){
          strMap[str[windowStart]]--;
          if(strMap[str[windowStart]] == 0){
            strMap.erase(str[windowStart]);
          }
          windowStart++;
        }
        strMap[str[windowStart]]--;
        if(strMap[str[windowStart]] == 0){
            strMap.erase(str[windowStart]);
          }
        windowStart++;
      }
      if(size == strMap.size()){
        return true;
      }
      

    }
    return false;
  }
};
