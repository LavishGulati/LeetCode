class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }

        int si = 0, ei = 0;
        int ans = n+1, sum = nums[0];
        while(si < n && ei < n){
            while(sum < s){
                ei++;
                if(ei == n){
                    break;
                }
                sum += nums[ei];
            }

            if(sum >= s){
                ans = min(ans, ei-si+1);
            }

            sum -= nums[si];
            si++;
            if(ei < si){
                ei++;
                sum += nums[ei];
            }
        }
        return (ans > n ? 0 : ans);
    }
};
