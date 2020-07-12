#define all(x) x.begin(), x.end()
#define pb push_back

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set< vector<int> > myset;
        int n = nums.size(), sum;
        vector<int> v;
        sort(all(nums));
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int k = j+1;
                int l = n-1;
                while(k < l){
                    sum = nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum < target){
                        k++;
                    }
                    else if(sum > target){
                        l--;
                    }
                    else{
                        v.clear();
                        v.pb(nums[i]);
                        v.pb(nums[j]);
                        v.pb(nums[k]);
                        v.pb(nums[l]);
                        myset.insert(v);
                        k++;
                    }
                }
            }
        }
        
        vector< vector<int> > output;
        for(auto x : myset){
            output.pb(x);
        }
        return output;
    }
};