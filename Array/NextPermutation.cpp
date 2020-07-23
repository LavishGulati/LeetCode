class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2, j, id, x;
        while(i >= 0 && nums[i] >= nums[i+1]){
            i--;
        }

        if(i < 0){
            j = n-1, i = 0;
            while(i < j){
                swap(nums[i], nums[j]);
                i++; j--;
            }
        }
        else{
            id = n-2, x = INT_MAX;
            for(int j = n-1; j > i; j--){
                if(nums[j] > nums[i] && x > nums[j]){
                    x = nums[j];
                    id = j;
                }
            }

            swap(nums[id], nums[i]);
            j = n-1, id = i+1;
            while(id < j){
                swap(nums[id], nums[j]);
                id++; j--;
            }
        }
    }
};
