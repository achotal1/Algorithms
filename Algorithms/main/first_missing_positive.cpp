class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ind = 1;
        for(int i = 0; i<nums.size();i++){
            if(nums[i] < ind){
                continue;
            }
            if(nums[i] == ind)
            ind++;
            if(nums[i] > ind){
                return ind;
            }
        }
        return nums.size();
    }
    int firstMissingPositiveHashSet(vector<int>& nums){
        int ind = 1;
        unordered_set<int> s;
        for(int i = 0; i<nums.size();i++){
            s.insert(nums[i]);
        }
        for(ind = 1; ind<nums.size() + 1; ind++){
            if(s.find(ind) != s.end()){
                continue;
            }
            else{
                return ind;
            }
        }
        return nums.size() + 1;

    }
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] <= 0){
                nums[i] = nums.size() + 1;
            }
        }
        for(int i = 0; i<nums.size(); i++){
            if(abs(nums[i]) <= nums.size() && nums[abs(nums[i]) - 1] > 0)
            nums[abs(nums[i]) - 1] *= -1;
        }
        for(int i = 1; i<=nums.size(); i++){
            if(nums[i - 1] > 0){
                return i;
            }
        }
        return nums.size() + 1;
    }
};
