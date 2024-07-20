class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int rows = rowSum.size(), cols = colSum.size();
        vector<vector<int>> matrix(rows, vector<int>(cols));
        
        for(int i=0 ; i<rows ; i++){
            for(int j=0 ; j<cols ; j++){
                int val = min(rowSum[i], colSum[j]);
                matrix[i][j] = val;
                
                rowSum[i] -= val;
                colSum[j] -= val;
            }
        }
        
        return matrix;
    }
};