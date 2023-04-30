class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        int prod(1); int hasZero = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0){
                hasZero++;
                continue;
            }
            prod *= nums[i];
        }
        for(int i = 0; i<nums.size(); i++){
           if(hasZero > 1){
               res[i] = 0;
               continue;
           }else if(hasZero == 1){
               if(nums[i] == 0){
                   res[i] = prod;
               }else{
                   res[i] = 0;
               }
               continue;
           }
           res[i] = prod/nums[i];
        }
        return res;
    }
    int calculate(vector<int> nums, int low, int high){
        int p = 1;
        for(int i = low; i<=high; i++){
            p *= nums[i];
        }
        return p;
    }
};