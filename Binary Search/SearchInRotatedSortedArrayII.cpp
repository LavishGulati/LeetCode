class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int si = 0, ei = n-1, mid;
        bool start;
        while(si <= ei){
            mid = (si+ei)/2;
            if(nums[si] == nums[mid] || nums[ei] == nums[mid]){
                start = true;
                for(int i = si; i < mid; i++){
                    if(nums[i] != nums[i+1]){
                        start = false;
                        break;
                    }
                }
                if(start){
                    if(nums[mid] != target){
                        si = mid+1;
                    }
                    else{
                        return true;
                    }
                }
                else{
                    if(nums[mid] != target){
                        ei = mid-1;
                    }
                    else{
                        return true;
                    }
                }
            }
            else if(nums[mid] > nums[si]){
                if(target < nums[si] || target > nums[mid]){
                    si = mid+1;
                }
                else if(target == nums[si] || target == nums[mid]){
                    return true;
                }
                else{
                    ei = mid-1;
                }
            }
            else if(nums[mid] < nums[ei]){
                if(target < nums[mid] || target > nums[ei]){
                    ei = mid-1;
                }
                else if(target == nums[ei] || target == nums[mid]){
                    return true;
                }
                else{
                    si = mid+1;
                }
            }
        }
        return false;
    }
};
