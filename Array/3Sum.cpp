#define all(x) x.begin(), x.end()
#define pb push_back

class Solution {
public:
    set<vector<int>> myset;
    vector< vector<int> > output;
    vector<int> v;
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        myset.clear();
        
        sort(all(nums));
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            int j = i+1;
            int k = n-1;
            while(j < k){
                if(nums[i]+nums[j]+nums[k] > 0){
                    k--;
                }
                else if(nums[i]+nums[j]+nums[k] < 0){
                    j++;
                }
                else{
                    v.clear();
                    v.pb(nums[i]);
                    v.pb(nums[j]);
                    v.pb(nums[k]);
                    myset.insert(v);
                    j++;
                }
            }
        }
        
        output.clear();
        for(auto v : myset){
            output.pb(v);
        }
        return output;
    }
};