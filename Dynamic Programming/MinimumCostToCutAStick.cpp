#define pb push_back
#define all(x) x.begin(), x.end()

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(all(cuts));

        vector<int> arr;
        arr.pb(0);
        for(int x : cuts){
            arr.pb(x);
        }
        arr.pb(n);
        n = arr.size();

        int **dp = new int *[n];
        for(int i = 0; i < n; i++){
            dp[i] = new int[n];
            for(int j = 0; j < n; j++){
                dp[i][j] = 0;
            }
        }

        int l = 2;
        while(l < n){
            for(int i = 0; i < n-l; i++){
                dp[i][i+l] = INT_MAX;
                for(int k = i+1; k < i+l; k++){
                    dp[i][i+l] = min(dp[i][i+l], dp[i][k]+dp[k][i+l]+arr[i+l]-arr[i]);
                }
            }
            l++;
        }

        return dp[0][n-1];
    }
};
