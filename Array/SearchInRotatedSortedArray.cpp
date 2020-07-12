class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        int si = 0;
        int ei = n-1;
        while(si <= ei){
            int mid = (si+ei)/2;
            if(nums[ei] > nums[si]){
                if(nums[mid] < target){
                    si = mid+1;
                }
                else if(nums[mid] > target){
                    ei = mid-1;
                }
                else{
                    return mid;
                }
            }
            else{
                if(nums[mid] >= nums[si]){
                    if(target >= nums[si] && target < nums[mid]){
                        ei = mid-1;
                    }
                    else if(target == nums[mid]){
                        return mid;
                    }
                    else{
                        si = mid+1;
                    }
                }
                else{
                    if(target > nums[mid] && target <= nums[ei]){
                        si = mid+1;
                    }
                    else if(target == nums[mid]){
                        return mid;
                    }
                    else{
                        ei = mid-1;
                    }
                }
            }
        }
        return -1;
    }
};