class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int currRange = nums[0], i;
        for(i = 1; i < n; i++){
            if(i <= currRange){
                currRange = max(currRange, i+nums[i]);
            }
            else{
                break;
            }
        }
        if(i == n){
            return true;
        }
        else{
            return false;
        }
    }
};
