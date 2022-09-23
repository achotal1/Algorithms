using namespace std;

#include <iostream>
#include <vector>

class CyclicSort {
 public:
  static void sort(vector<int> &nums) {
    int i = 0;
    while(i < nums.size()){
      int j = nums[i];
      if(nums[i] != i+1){
        nums[j-1] = j;
        nums[i] = i+1;
      }
      else{
        i++;
      }
    }
    
  }
};