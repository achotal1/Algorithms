class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        //int sum(0);
        for(int i = 0; i<numRows; i++){
            //vector<int> sample;
            for(int j = 0; j<= i; j++){
                if(j == 0 || j == i){
                    res[i].push_back(1);
                }
                else{
                    res[i].push_back(res[i-1][j-1] + res[i-1][j]);
                }
            }
            //res.push_back(sample);
        }
        return res;
    }
};