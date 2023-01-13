class Solution {
    private:
    bool validMove(int i, int j, vector<vector<char>> &grid, int n, int m){  //a function to check move is irght or wrong
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j] == '1')
            return true;
        return false;        
    }
    void dfs(vector<vector<char>> &grid, int i, int j, int n, int m){
        
        grid[i][j] = -1;
        if(validMove(i+1, j, grid, n, m))
            dfs(grid, i+1, j, n, m);
            
        if(validMove(i-1, j, grid, n, m))
            dfs(grid, i-1, j, n, m);
            
        if(validMove(i, j+1, grid, n, m))
            dfs(grid, i, j+1, n, m);
            
        if(validMove(i, j-1, grid, n, m))
            dfs(grid, i, j-1, n, m);
            
        if(validMove(i+1, j+1, grid, n, m))
            dfs(grid, i+1, j+1, n, m);
            
        if(validMove(i+1, j-1, grid, n, m))
            dfs(grid, i+1, j-1, n, m);
            
        if(validMove(i-1, j+1, grid, n, m))
            dfs(grid, i-1, j+1, n, m);
            
        if(validMove(i-1, j-1, grid, n, m))
            dfs(grid, i-1, j-1, n, m);
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(grid, i, j, n, m);
                }
            }
        }
        return ans;
    }
};
