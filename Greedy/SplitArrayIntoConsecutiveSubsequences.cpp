#define umap unordered_map

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        umap<int, int> freq;
        for(int x : nums){
            freq[x]++;
        }

        umap<int, int> tails;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(freq[nums[i]] == 0){
                continue;
            }
            else if(tails[nums[i]-1] > 0){
                tails[nums[i]]++;
                tails[nums[i]-1]--;
            }
            else if(freq[nums[i]+1] > 0 && freq[nums[i]+2] > 0){
                freq[nums[i]+1]--;
                freq[nums[i]+2]--;
                tails[nums[i]+2]++;
            }
            else{
                return false;
            }
            freq[nums[i]]--;
        }

        return true;
    }
};
