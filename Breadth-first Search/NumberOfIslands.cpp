class Solution {
public:
    int moveX[4] = {1, -1, 0, 0};
    int moveY[4] = {0, 0, 1, -1};

    void dfs(vector<vector<char>> &grid, int ui, int uj, int n, int m){
        grid[ui][uj] = '0';
        for(int i = 0; i < 4; i++){
            int vi = ui+moveX[i];
            int vj = uj+moveY[i];
            if(vi >= 0 && vi < n & vj >= 0 && vj < m && grid[vi][vj] == '1'){
                dfs(grid, ui+moveX[i], uj+moveY[i], n, m);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        if(n == 0){
            return ans;
        }

        int m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(grid, i, j, n, m);
                }
            }
        }
        return ans;
    }
};
