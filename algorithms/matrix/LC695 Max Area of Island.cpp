class Solution {
    public:
        void dfs(vector<vector<int>>& grid, int i, int j, int  & x){  
            
            if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1){
                return;
            }

            grid[i][j] = 0;
            
            x++;
            dfs(grid, i + 1, j, x);
            dfs(grid, i - 1, j, x);
            dfs(grid, i, j - 1, x);
            dfs(grid, i, j + 1, x);

        }
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            int mx = 0;
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < m; ++j){
                    int x = 0;
                    if(grid[i][j] == 1){
                        dfs(grid, i, j, x);
                        mx = max(x, mx);
                    }
                }
            }     
            return mx;
        }
};