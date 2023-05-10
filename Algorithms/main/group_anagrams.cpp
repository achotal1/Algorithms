class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> res;
        for(auto i: strs){
            string ans = i;
            sort(ans.begin(), ans.end());
            m[ans].push_back(i);
        }
        for(auto j: m){
            res.push_back(j.second);
        }
        return res;
    }
};