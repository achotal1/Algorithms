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

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int size = s1.length();
        unordered_map<char,int> map1;
        unordered_map<char,int> map2;
        int windowStart(0),windowlen(0);
        for(int i = 0; i<s1.length(); i++){
            map1[s1[i]]++;
        }
        for(int windowEnd = 0; windowEnd<s2.length(); windowEnd++){
            windowlen = windowEnd - windowStart + 1;
            map2[s2[windowEnd]]++;
            if(windowlen == size){
                if(map1 == map2){
                    return true;
                }
                map2[s2[windowStart]]--;
                if(map2[s2[windowStart]] == 0){
                    map2.erase(s2[windowStart]);
                }
                windowStart++;
            }
        }
        return false;

    }
};
// using namespace std;

// #include <iostream>
// #include <string>
// #include <unordered_map>
// class StringPermutation {
//  public:
//   static bool findPermutation(const string &str, const string &pattern) {
//     // TODO: Write your code here
//     unordered_map<char,int> patternMap;
//     unordered_map<char,int> strMap;
//     for(int i = 0; i< pattern.length(); i++){
//       patternMap[pattern[i]]++;
//     }
//     int size = patternMap.size();
//     int windowStart = 0;
//     for(int windowEnd = 0; windowEnd < str.length(); windowEnd++){
//       strMap[str[windowEnd]]++;
      
//       if(patternMap.find(str[windowEnd]) == patternMap.end() && strMap[str[windowEnd]] > patternMap[str[windowEnd]]){
//         while(windowStart != windowEnd){
//           strMap[str[windowStart]]--;
//           if(strMap[str[windowStart]] == 0){
//             strMap.erase(str[windowStart]);
//           }
//           windowStart++;
//         }
//         strMap[str[windowStart]]--;
//         if(strMap[str[windowStart]] == 0){
//             strMap.erase(str[windowStart]);
//           }
//         windowStart++;
//       }
//       if(size == strMap.size()){
//         return true;
//       }
      

//     }
//     return false;
//   }
// };
