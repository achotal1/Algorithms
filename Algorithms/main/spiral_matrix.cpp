class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowSize = matrix.size();
        int columnSize = matrix[0].size();
        int top = 0,bottom = rowSize - 1, left = 0, right = columnSize - 1;
        vector<int> res;
        while(res.size() < rowSize*columnSize){
            if(left <= right){
                for(int i = left; i<=right; i++){
                    res.push_back(matrix[top][i]);
                }
                top++;
            }
            if(top <= bottom && res.size() < rowSize*columnSize){
                for(int i = top; i<=bottom; i++){
                    res.push_back(matrix[i][right]);
                }
                right--;
            }
            if(right >= left && res.size() < rowSize*columnSize){
                 for(int i = right; i>=left; i--){
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(bottom >= top && res.size() < rowSize * columnSize){
                for(int i = bottom; i>=top; i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};