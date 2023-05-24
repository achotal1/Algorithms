class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool ans = false;
        if(nums.size() <= 2){
            return true;
        }
        for(int i = 0; i<nums.size(); i++){
            int temp = nums[i];
            if(i == 0){
                nums[i] = nums[i+1]<nums[i] ? nums[i + 1]: nums[i];
            }else if(i == nums.size() - 1){
                nums[i] = nums[i - 1] > nums[i] ? nums[i-1]: nums[i];
            }else{
                if(nums[i-1] > nums[i] && nums[i] > nums[i+1]){
                    continue;
                }else if(nums[i - 1] > nums[i]){
                    nums[i] = nums[i-1];
                }else if(nums[i] > nums[i+1]){
                    nums[i] = nums[i+1];
                }
            }
            ans = ans | check_if_sorted(nums);
            if(ans == true)return true;
            nums[i] = temp;
        }
        return ans;
    }
    bool check_if_sorted(vector<int> nums){
        for(int i = 0; i<nums.size() - 1 ; i++){
            if(nums[i] > nums[i+1]){
                return false;
            }
        }
        return true;
    }

};