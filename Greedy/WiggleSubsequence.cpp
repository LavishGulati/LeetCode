class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1){
            return n;
        }

        int j = 0;
        int k = 1;
        while(k < n && nums[j] == nums[k]){
            k++;
        }
        if(k == n){
            return 1;
        }

        int m = 2;
        for(int i = k+1; i < n; i++){
            if(nums[k]-nums[j] > 0){
                if(nums[i]-nums[k] < 0){
                    j = k;
                    k = i;
                    m++;
                }
                else{
                    k = i;
                }
            }
            else{
                if(nums[i]-nums[k] > 0){
                    j = k;
                    k = i;
                    m++;
                }
                else{
                    k = i;
                }
            }
        }
        return m;
    }
};
