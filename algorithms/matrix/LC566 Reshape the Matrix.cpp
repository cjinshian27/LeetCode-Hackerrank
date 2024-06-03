class Solution {
    public:
        vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
            
            int n = mat.size();
            int m = mat[0].size();
            
            if(n * m != r * c){
                return mat;
            }  
            
            vector<vector<int>> reshape(r, vector<int>(c));
            int row = 0, column = 0;
            
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < m; ++j){
                    reshape[row][column++] = mat[i][j];
                    
                    if(column == c){
                        column = 0;
                        ++row;
                    }
                }
            }
            
            return reshape;
        }
};