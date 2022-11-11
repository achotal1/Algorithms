/*

Comparing Strings containing Backspaces (medium)#
Given two strings containing backspaces (identified by the character ‘#’), 
check if the two strings are equal.

Example 1:

Input: str1="xy#z", str2="xzz#"
Output: true
Explanation: After applying backspaces the strings become "xz" and "xz" respectively.
Example 2:

Input: str1="xy#z", str2="xyz#"
Output: false
Explanation: After applying backspaces the strings become "xz" and "xy" respectively.


*/

using namespace std;

#include <iostream>
#include <string>

class BackspaceCompare {
 public:
  static bool compare(const string &str1, const string &str2) {
    int ptr1(str1.length()-1);
    int ptr2(str2.length()-1);
    int buffer1 = 0, buffer2 = 0;
    while(ptr1 != -1 || ptr2 != -1){
      int one = findChar(ptr1, str1);
      int two = findChar(ptr2, str2);
      if(one <= 0 && two <= 0)
      {
        return true;
      }
      if(one <= 0 || two <= 0){
        return false;
      }
      if(str1[one] != str2[two]){
        return false;
      }
      ptr1 = one - 1;
      ptr2 = two - 1;
      
    }
    return true;
  }
  static int findChar(int ptr, const string &str){
    int backspace = 0;
    while(ptr >= 0){
      if(str[ptr] == '#'){
        backspace++;
        ptr--;
      }
      else if(backspace > 0){
        backspace--;
        ptr--;
      }
      else{
        break;
      }
    }
    return ptr;
  }
};
