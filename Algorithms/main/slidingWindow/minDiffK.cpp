class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int windowStart = 0;
        int ans = std::numeric_limits<int>::max();
        for(int windowEnd = 0; windowEnd<nums.size(); windowEnd++){
            if(windowEnd - windowStart + 1 == k){
                ans = min(ans, nums[windowEnd] - nums[windowStart]);
                windowStart++;
            }
        }
        return ans;
    }
};