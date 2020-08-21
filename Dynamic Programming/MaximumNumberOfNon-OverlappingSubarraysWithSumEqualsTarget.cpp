#define umap unordered_map
#define pb push_back

class Solution {
public:
    int binary_search(vector<int> &v, int x){
        int si = 0, ei = v.size()-1, mid;
        int ans = -1;
        while(si <= ei){
            mid = (si+ei)/2;
            if(v[mid] >= x){
                ans = v[mid];
                ei = mid-1;
            }
            else{
                si = mid+1;
            }
        }
        return ans;
    }

    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();

        int *cum = new int[n];
        umap<int, vector<int>> mp;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            cum[i] = sum;
            mp[sum].pb(i);
        }

        int *dp = new int[n];
        for(int i = 0; i < n; i++){
            dp[i] = 0;
        }
        dp[n-1] = (nums[n-1] == target ? 1 : 0);

        for(int i = n-2; i >= 0; i--){
            dp[i] = dp[i+1];

            int j = -1;
            sum = target + (i > 0 ? cum[i-1] : 0);
            if(mp.find(sum) != mp.end()){
                j = binary_search(mp[sum], i);
            }

            if(j != -1){
                if(j+1 < n){
                    dp[i] = max(dp[i], dp[j+1]+1);
                }
                else if(j+1 >= n){
                    dp[i] = max(dp[i], 1);
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
