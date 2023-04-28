class Solution {
public:
    int arithmeticTriplets2(vector<int>& nums, int diff) {
        int c = 0;
        for(int first = 0; first < nums.size(); first++){
            for(int second = first + 1; second<nums.size(); second++){
                if(nums[second] - nums[first] == diff){
                    for(int third = second + 1; third<nums.size(); third++){
                        if(nums[third] - nums[second] == diff){
                            c++;
                        }
                    }
                }
            }
        }
        return c;
    }
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int c = 0;
        unordered_map<int,bool> map;
        for(int i = 0; i<nums.size(); i++){
            map[nums[i]] = true;
        }
        for(int i = 0; i<nums.size(); i++){
            if(map[nums[i] - diff] && map[nums[i]+diff]){
                c++;
            }
        }

        return c;
    }
};