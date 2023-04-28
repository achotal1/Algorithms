class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> v(grid[0].size() - 2, vector<int>(grid[0].size() - 2));
        int mx;
        for(int i = 0; i<v.size();i++){
            vector<int> temp;
            for(int j = 0; j<v.size(); j++){
                mx = 0;
                for(int k = i; k<i+3; k++){
                    for(int o = j; o<j+3; o++){
                        mx = max(mx, grid[k][o]);
                    }
                }
                temp.push_back(mx);
            }
            v[i] = temp;
            
        }
        return v;
    }
};