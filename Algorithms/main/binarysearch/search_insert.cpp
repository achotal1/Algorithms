class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return helper(nums, target, 0, nums.size() - 1);
    }
    int helper(vector<int> nums, int target, int start, int end){
        if(start > end){
            return start;
        }
        int mid = (start + end)/2;
        if(nums[mid] > target){
            return helper(nums,target, start, mid - 1);
        }
        else if(nums[mid] < target){
            return helper(nums, target, mid + 1, end);
        }
        else{
            return mid;
        }
    }
};

Better version:

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        int mid = 0;
        while(left < right){
            mid = left + (right - left)/2;
            if(nums[mid] >= target){
                right = mid;
            }
            else
                left = mid + 1;
           
        }
        return left;
    }
};