#define pb push_back

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        
        int si = 0, ei = n-1, mid, small = -1;
        while(si <= ei){
            mid = (si+ei)/2;
            if(nums[mid] < target){
                si = mid+1;
            }
            else if(nums[mid] > target){
                ei = mid-1;
            }
            else{
                ei = mid-1;
                small = mid;
            }
        }
        
        vector<int> output;
        
        if(mid == -1){
            output.pb(-1);
            output.pb(-1);
            return output;
        }
        
        si = 0, ei = n-1;
        int big = -1;
        while(si <= ei){
            mid = (si+ei)/2;
            if(nums[mid] < target){
                si = mid+1;
            }
            else if(nums[mid] > target){
                ei = mid-1;
            }
            else{
                si = mid+1;
                big = mid;
            }
        }
        
        output.pb(small);
        output.pb(big);
        return output;
    }
};