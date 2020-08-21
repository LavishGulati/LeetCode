#define umap unordered_map
#define pb push_back

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        umap<int, int> mp;
        vector<int> output;
        for(int i = 0; i < n; i++){
            if(mp.find(target-nums[i]) == mp.end()){
                mp[nums[i]] = i;
            }
            else{
                output.pb(mp[target-nums[i]]);
                output.pb(i);
                return output;
            }
        }
        return output;
    }
};
