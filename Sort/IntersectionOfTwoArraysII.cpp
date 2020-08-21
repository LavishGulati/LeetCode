#define umap unordered_map
#define pb push_back

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> output;
        umap<int, int> mp;

        for(int x : nums2){
            mp[x]++;
        }

        for(int x : nums1){
            if(mp.find(x) != mp.end() && mp[x] > 0){
                mp[x]--;
                output.pb(x);
            }
        }
        return output;
    }
};
