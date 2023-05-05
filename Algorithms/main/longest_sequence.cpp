class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i = 0; i<nums.size(); i++){
            m[nums[i]]++; 
        }
        int mx(0),c(0);
        for(auto i: m){
            int temp = i.first;
            if(m.find(temp - 1) != m.end()) continue;
            c = 1;
            while(m.find(temp + 1) != m.end()){
                c++;
                temp++;
            }
            mx = max(mx, c);
        }
        return mx;
    }
};