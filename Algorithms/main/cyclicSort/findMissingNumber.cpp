using namespace std;

#include <iostream>
#include <vector>

class MissingNumber {
 public:
  static int findMissingNumber(vector<int> &nums){
    int i = 0;
    int missingNum = 0;
    while( i < nums.size()){
      if(nums[i] < nums.size() && nums[i] != i){
        int temp = nums[i];
        nums[i] = nums[nums[i]];
        nums[nums[i]] = temp;
      }
      else
      {
        i++;
      }
    }
    for(int j = 0; j<nums.size();j++){
      if(nums[j] != i){
        missingNum = nums[j];
        return missingNum;
      }
    }
    return nums.size();
  }
  
};
