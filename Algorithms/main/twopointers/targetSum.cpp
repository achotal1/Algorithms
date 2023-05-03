using namespace std;

#include <iostream>
#include <vector>

class PairWithTargetSum {
 public:
  static pair<int, int> search(const vector<int>& arr, int targetSum) {
    int ptr1(0),ptr2(arr.size()-1);
    for(int i = 0; i<arr.size();i++){
      if(arr[ptr1] + arr[ptr2] == targetSum){
        return make_pair(ptr1,ptr2);
      }
      else if(arr[ptr1] + arr[ptr2] < targetSum){
        ptr1++;
      }
      else if(arr[ptr1] + arr[ptr2] > targetSum){
        ptr2--;
      }
    }
    return make_pair(-1, -1);
  }
}
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        int sec = 0;
        for(int i = 0; i< nums.size(); i++){
            sec = target - nums[i];
            if(map.find(sec) != map.end()){
                return { map[sec], i};
            }
            else{
                map[nums[i]] = i;
            }
        }
        return {-1 , -1};
    }
};;
