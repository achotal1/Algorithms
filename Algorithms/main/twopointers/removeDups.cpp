using namespace std;

#include <iostream>
#include <vector>

class RemoveDuplicates {
 public:
  static int remove(vector<int>& arr) {
    int ptr1(0),ptr2(1);
    int c(0);
    for(int i = 0; i<arr.size(); i++){
      if(ptr2 == arr.size()+1){
        break;
      }
      if(arr[ptr1] == arr[ptr2]){
        ptr1++;
        ptr2++;
      }
      else if(arr[ptr1] != arr[ptr2]){
        ptr1++;
        ptr2++;
        c++;
      }
    }
    return c;
  }
};
