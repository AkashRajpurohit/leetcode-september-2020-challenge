class Solution {
private:
    int dfs(int i, int j, vector<vector<int>>& grid, int zero) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] == -1) return 0;
        
        if(grid[i][j] == 2) 
            return zero == -1 ? 1 : 0;
        
        grid[i][j] = -1;
        zero--;
        
        int total = dfs(i + 1, j, grid, zero) + 
            dfs(i - 1, j, grid, zero) + 
            dfs(i, j + 1, grid, zero) + 
            dfs(i, j - 1, grid, zero);
        
        grid[i][j] = 0;
        zero++;
        
        return total;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int zero = 0;
        
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(grid[i][j] == 0) zero++;
            }
        }
        
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(grid[i][j] == 1) {
                    return dfs(i, j, grid, zero);
                }
            }
        }
        
        return 0;
    }
};