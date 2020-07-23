class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n-1, k = 0;
        while(i < j){
            if(nums[i] > nums[j]){
                swap(nums[i], nums[j]);
            }
            else if(nums[i] == 0){
                i++;
            }
            else if(nums[j] == 2){
                j--;
            }
            else{
                k = max(k, i+1);
                while(k < j && nums[k] == 1){
                    k++;
                }
                if(k == j){
                    break;
                }
                if(nums[k] == 2){
                    swap(nums[j], nums[k]);
                    j--;
                }
                else{
                    swap(nums[i], nums[k]);
                    i++;
                }
            }
        }
    }
};
