class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int **dp = new int *[n];
        for(int i = 0; i < n; i++){
            dp[i] = new int[n];
            for(int j = 0; j < n; j++){
                dp[i][j] = 0;
            }
        }
        
        int i = 0, j = 0, l = 1;
        while(l <= n){
            while(i < n && j+l-1 < n){
                if(l == 1){
                    dp[i][j+l-1] = 1;
                }
                else if(l == 2){
                    if(s[i] == s[j+l-1]){
                        dp[i][j+l-1] = 2;
                    }
                    else{
                        dp[i][j+l-1] = 1;
                    }
                }
                else{
                    if(s[i] == s[j+l-1]){
                        dp[i][j+l-1] = 2+dp[i+1][j+l-2];
                    }
                    else if(dp[i+1][j+l-1] >= dp[i][j+l-2]){
                        dp[i][j+l-1] = dp[i+1][j+l-1];
                    }
                    else{
                        dp[i][j+l-1] = dp[i][j+l-2];
                    }
                }
                
                i++; j++;
            }
            
            l++; i = 0; j = 0;
        }
        
        return dp[0][n-1];
    }
};