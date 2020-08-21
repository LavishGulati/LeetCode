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
        for(int i = 2; i < n-1; i++){
            dp[i] = nums[i];
            if(i-3 >= 0){
                dp[i] += max(dp[i-3], dp[i-2]);
            }
            else{
                dp[i] += dp[i-2];
            }
            ans = max(ans, dp[i]);
        }

        if(n == 2){
            return ans;
        }

        dp[1] = nums[1];
        dp[2] = nums[2];
        ans = max(ans, max(dp[1], dp[2]));
        for(int i = 3; i < n; i++){
            dp[i] = nums[i];
            if(i-3 >= 1){
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
