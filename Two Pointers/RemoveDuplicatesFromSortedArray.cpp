class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, j = 1, n = nums.size();
        if(n == 0){
            return 0;
        }

        while(i < n){
            if(nums[i] == nums[i-1]){
                i++;
            }
            else{
                nums[j] = nums[i];
                i++; j++;
            }
        }
        return j;
    }
};
