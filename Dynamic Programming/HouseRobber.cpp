class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        else if(n == 1){
            return nums[0];
        }

        int *dp = new int[n], ans = 0;
        dp[0] = nums[0];
        dp[1] = nums[1];
        ans = max(dp[0], dp[1]);
        for(int i = 2; i < n; i++){
            dp[i] = nums[i];
            if(i-3 >= 0){
                dp[i] += max(dp[i-3], dp[i-2]);
            }
            else{
                dp[i] += dp[i-2];
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
