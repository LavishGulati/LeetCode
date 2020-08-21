// Solution 1 -- O(nlogn + mlogm) time

#define all(x) x.begin(), x.end()
#define pb push_back

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(all(nums1));
        sort(all(nums2));

        int n = nums1.size(), m = nums2.size();
        vector<int> output;
        int i = 0, j = 0;
        while(i < n && j < m){
            if(nums1[i] < nums2[j]){
                i++;
            }
            else if(nums1[i] > nums2[j]){
                j++;
            }
            else{
                if(output.empty() || output.back() != nums1[i]){
                    output.pb(nums1[i]);
                }
                i++; j++;
            }
        }

        return output;
    }
};


// Solution 2 - O(n+m) time and O(n+m) space
#define umap unordered_map
#define pb push_back

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        umap<int, bool> mp;
        int n = nums1.size(), m = nums2.size();
        vector<int> output;
        for(int x : nums2){
            mp[x] = false;
        }

        for(int x : nums1){
            if(mp.find(x) != mp.end() && !mp[x]){
                mp[x] = true;
                output.pb(x);
            }
        }
        return output;
    }
};
