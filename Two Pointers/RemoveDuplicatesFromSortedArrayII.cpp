class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 1, len = 0, id = 0;
        while(j < n){
            if(nums[i] != nums[j]){
                nums[id] = nums[i];
                len++; id++;
                i++; j++;
            }
            else{
                len += 2;
                nums[id] = nums[i];
                nums[id+1] = nums[i];
                id += 2;
                while(j < n && nums[j] == nums[i]){
                    j++;
                }
                i = j;
                j++;
            }
        }
        if(i < n){
            nums[id] = nums[i];
            len++;
        }
        return len;
    }
};
