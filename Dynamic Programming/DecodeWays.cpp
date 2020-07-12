class Solution {
public:
    bool isnumber(char x, char y){
        if(x == '1' && y >= '0' && y <= '9'){
            return true;
        }
        else if(x == '2' && y >= '0' && y <= '6'){
            return true;
        }
        return false;
    }
    
    int numDecodings(string s) {
        int n = s.length();
        
        int *dp = new int[n];
        dp[0] = 0;
        if(s[0] >= '1' && s[0] <= '9'){
            dp[0] = 1;
        }
        
        if(n == 1){
            return dp[0];
        }
        
        dp[1] = 0;
        if(s[1] >= '1' && s[1] <= '9'){
            dp[1] += dp[0];
        }
        if(isnumber(s[0], s[1])){
            dp[1] += 1;
        }
        
        for(int i = 2; i < n; i++){
            dp[i] = 0;
            if(s[i] >= '1' && s[i] <= '9'){
                dp[i] += dp[i-1];
            }
            if(isnumber(s[i-1], s[i])){
                dp[i] += dp[i-2];
            }
        }
        return dp[n-1];
    }
};