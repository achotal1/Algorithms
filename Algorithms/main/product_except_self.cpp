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

Better version with O(n) time plus O(n) space in comments and constant space otherwise:

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);
        // vector<int> prefix(n);
        // vector<int> postfix(n);
        // prefix[0] = nums[0];
        // for(int i = 1; i<nums.size(); i++){
        //     prefix[i] = prefix[i-1] * nums[i];
        // }
        // postfix[n-1] = nums[n-1];
        // for(int i = n-2; i>=0; i--){
        //     postfix[i] = postfix[i+1] * nums[i];
        // }

        // for(int i = 0; i<=n-1; i++){
        //     if(i == 0){
        //         output[i] = 1 * postfix[i+1];
        //     }else if(i == (n-1)){
        //         output[i] = prefix[i-1] * 1;
        //     }
        //     else{
        //         output[i] = prefix[i-1] * postfix[i+1];
        //     }
            
        // }
        int prefix = 1;
        for(int i = 0; i<n; i++){
            output[i] = prefix;
            prefix *= nums[i];
        }
        int postfix = 1;
        for(int i = n-1; i>=0; i--){
            output[i] *= postfix;
            postfix *= nums[i];
        }



        return output;
    }
};