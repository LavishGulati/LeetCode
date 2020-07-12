#define all(x) x.begin(), x.end()

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;
        while(i >= 0 && nums[i] >= nums[i+1]){
            i--;
        }
        
        if(i < 0){
            sort(all(nums));
            return;
        }
        
        int j = n-1;
        int id = -1;
        int big = -1;
        while(j > i){
            if(nums[j] > nums[i] && (nums[j] < big || big == -1)){
                big = nums[j];
                id = j;
            }
            j--;
        }
        
        swap(nums[i], nums[id]);
        sort(nums.begin()+i+1, nums.end());
    }
};