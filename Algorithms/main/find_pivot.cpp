class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       vector<int> leftsum(nums.size());
       vector<int> rightsum(nums.size());
       leftsum[0] = nums[0];
       for(int i = 1; i<nums.size(); i++){
           leftsum[i] = leftsum[i-1] + nums[i]; 
       }
       rightsum[nums.size() - 1] = nums[nums.size() - 1];
       for(int i = nums.size()-2; i>=0; i--){
           rightsum[i] = rightsum[i+1] + nums[i];
       }

       for(int i = 0; i<nums.size(); i++){
           if(leftsum[i] == rightsum[i]) return i;
       }
       return -1;
    }
};

//
// [1,7,3,6,5,6]
// [1,8,11,17,22,28]
// [28,27,20,17,11,6]
// [6,5,6,3,7,1]