class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }

        int si = 0, ei = n-1, mid;
        while(si <= ei){
            mid = (si+ei)/2;
            if(mid == 0){
                if(nums[mid] > nums[mid+1]){
                    return mid;
                }
                else{
                    si = mid+1;
                }
            }
            else if(mid == n-1){
                if(nums[mid] > nums[mid-1]){
                    return mid;
                }
                else{
                    ei = mid-1;
                }
            }
            else{
                if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                    return mid;
                }
                else if(nums[mid] > nums[mid-1]){
                    si = mid+1;
                }
                else if(nums[mid] > nums[mid+1]){
                    ei = mid-1;
                }
                else{
                    si = mid+1;
                }
            }
        }
        return -1;
    }
};
