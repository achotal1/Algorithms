class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<vector<int>> res;
        int jSize = matrix[0].size() - 1;
        int row = 0;
        for(int i = 0; i<matrix.size(); i++){
            if(matrix[i][jSize] == target)
                return true;
            else if(matrix[i][jSize] > target){
                row = i;
                break;
            }      
        }
        int mid = 0;
        int low = 0;
        int high = jSize;
        while(low <= high){
            mid = (low+high)/2;
            if(matrix[row][mid] == target)
                return true;
            else if(matrix[row][mid] > target){
                high = mid-1;
            }else{
                low = mid + 1;
            }
        }
        return false;
    }
};