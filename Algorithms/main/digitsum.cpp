class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int element = 0, digit = 0;
        for(auto i: nums){
            element += i;
        }
        for(int i = 0; i<nums.size(); i++){
            int k = nums[i];
            while(k > 0){
                digit += k%10;
                k /= 10;
            }
        }
        return abs(element - digit);
    }
};