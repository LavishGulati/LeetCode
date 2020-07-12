class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int **dp = new int *[m];
        for(int i = 0; i < m; i++){
            dp[i] = new int[n];
            for(int j = 0; j < n; j++){
                dp[i][j] = 0;
            }
        }
        
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                dp[i][j] = grid[i][j];
                if(j+1 < n && i+1 < m){
                    dp[i][j] += min(dp[i+1][j], dp[i][j+1]);
                }
                else if(j+1 < n){
                    dp[i][j] += dp[i][j+1];
                }
                else if(i+1 < m){
                    dp[i][j] += dp[i+1][j];
                }
            }
        }
        return dp[0][0];
    }
};