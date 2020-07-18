class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int si = 0, ei = n-1, mid, ans = nums[0];
        while(si <= ei){
            mid = (si+ei)/2;
            if(si == mid){
                ans = min(ans, nums[si]);
                si = mid+1;
            }
            else if(ei == mid){
                ans = min(ans, nums[ei]);
                ei = mid-1;
            }
            else if(nums[ei] > nums[mid]){
                ans = min(ans, nums[mid]);
                ei = mid-1;
            }
            else if(nums[mid] > nums[si]){
                ans = min(ans, nums[si]);
                si = mid+1;
            }
        }
        return ans;
    }
};
