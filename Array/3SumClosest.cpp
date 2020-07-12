#define all(x) x.begin(), x.end()

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(all(nums));
        
        int ans = 100000;
        int sum;
        for(int i = 0; i < n; i++){
            int j = i+1;
            int k = n-1;
            while(j < k){
                sum = nums[i]+nums[j]+nums[k];
                if(abs(target-sum) < abs(target-ans)){
                    ans = sum;
                }
                if(sum < target){
                    j++;
                }
                else if(sum > target){
                    k--;                    
                }
                else{
                    return target;
                }
            }
        }
        return ans;
    }
};