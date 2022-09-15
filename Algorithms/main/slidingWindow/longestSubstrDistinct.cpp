using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class NoRepeatSubstring {
 public:
  static int findLength(const string& str) {
    int maxLength = 0;
    unordered_map<char, int> charMap;
    int windowStart = 0;
    for(int windowEnd = 0; windowEnd < str.length(); windowEnd++){
      charMap[str[windowEnd]]++;
      while(charMap[str[windowEnd]] > 1){
        charMap[str[windowStart]]--;
        if(charMap[str[windowStart]] == 0){
          charMap.erase(str[windowStart]);
        }
        windowStart++;
      }
      maxLength = max(maxLength, windowEnd - windowStart + 1);
    }
    return maxLength;
  }
  static int findLengthLinearTime(const string& str) {
    int maxLength = 0;
    unordered_map<char, int> charMap;
    int windowStart = 0;
    for(int windowEnd = 0; windowEnd < str.length(); windowEnd++){
      char a = str[windowEnd];
      if(charMap.find(a) != charMap.end()){
        windowStart = max(windowStart, charMap[a] + 1);
      }
      charMap[a] = windowEnd;
      maxLength = max(maxLength, windowEnd - windowStart + 1);
    }
    return maxLength;
  }
};
