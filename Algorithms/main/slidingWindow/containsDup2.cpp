class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int windowStart(0), windowlen(0);
        for(int windowEnd = 0; windowEnd < nums.size(); windowEnd++){
            windowlen = windowEnd - windowStart + 1;
            map[nums[windowEnd]]++;
            if(windowlen < k+1){
                if(map[nums[windowEnd]] >= 2){
                    return true;
                }
            }
            else if(windowlen == k+1){
                //auto got = map.find(nums[windowStart]);
                if(map[nums[windowEnd]] >= 2){
                    return true;
                }
                //cout<<"WindowStart element"<<nums[windowStart]<<endl;
                map[nums[windowStart]]--;
                if(map[nums[windowStart]] == 0){
                    map.erase(nums[windowStart]);
                }
                windowStart++;
            }
        }
        return false;
    }
};