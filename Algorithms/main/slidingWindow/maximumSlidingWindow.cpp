#include <deque>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        for(int windowEnd = 0; windowEnd < nums.size(); windowEnd++){
            if(!dq.empty() && dq.front() < windowEnd - k + 1){
                dq.pop_front();
            }
            while(!dq.empty() && nums[windowEnd] > nums[dq.back()]){
                dq.pop_back();
            }
            
            dq.push_back(windowEnd);
            if(windowEnd >= (k-1)){
                res.push_back(nums[dq.front()]);
            }
            
        }
        return res;
    }
};