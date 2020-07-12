class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        int **dp = new int *[m];
        for(int i = 0; i < m; i++){
            dp[i] = new int[n];
            for(int j = 0; j < n; j++){
                dp[i][j] = 0;
            }
        }
        
        dp[0][0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else{
                    if(j-1 >= 0){
                        dp[i][j] += dp[i][j-1];
                    }
                    if(i-1 >= 0){
                        dp[i][j] += dp[i-1][j];
                    }
                }
            }
        }
        return dp[m-1][n-1];
    }
};