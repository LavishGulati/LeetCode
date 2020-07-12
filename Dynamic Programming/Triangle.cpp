#define pb push_back

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> help;
        vector<int> output;
        output.pb(triangle[0][0]);
        for(int i = 1; i < n; i++){
            help = output;
            output.clear();
            for(int j = 0; j <= i; j++){
                if(j == 0){
                    output.pb(help[0]+triangle[i][j]);
                }
                else if(j == i){
                    output.pb(help[j-1]+triangle[i][j]);
                }
                else{
                    output.pb(triangle[i][j] + min(help[j-1], help[j]));
                }
            }
        }
        
        int ans = INT_MAX;
        for(int i = 0; i < output.size(); i++){
            ans = min(ans, output[i]);
        }
        return ans;
    }
};