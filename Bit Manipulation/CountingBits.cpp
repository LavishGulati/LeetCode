class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1);
        dp[0] = 0;
        int x, d;
        for(int i = 1; i <= num; i++){
            x = i, d = 0;
            while(!(x%2)){
                d++;
                x /= 2;
            }
            dp[i] = 1+(dp[i>>(d+1)]);
        }
        return dp;
    }
};
