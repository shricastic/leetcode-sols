class Solution {
private: 
    int findmin(vector<int> arr){
        sort(arr.begin(), arr.end());
        return arr[0];
    }
    
    bool ismax(vector<vector<int>> matrix, int col, int min){
        for(int i=0 ; i<matrix.size() ; i++){
            if(matrix[i][col]>min){
                return false;
            }
        }
        
        return true;
    }
    
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        
        for(int i=0 ; i<matrix.size() ; i++){
            int min = findmin(matrix[i]);
            
            for(int j=0 ; j<matrix[i].size() ; j++){
                if(min == matrix[i][j]){
                    if(ismax(matrix, j, min)) res.push_back(min);
                }
            }
        }
        
        return res;
    }
};