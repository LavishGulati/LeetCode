// Solution 1 -- O(n) time and O(1) space
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int cnt, x;
        int ans = 0;
        for(int d = 0; d < 31; d++){
            cnt = 0;
            for(int i = 0; i < n; i++){
                if(nums[i]&(1<<d)){
                    cnt++;
                }
            }

            x = n;
            cnt -= (x/(1<<(d+1)))*(1<<d);
            x -= (x/(1<<(d+1)))*(1<<(d+1));
            cnt -= max(x-(1<<d)+1, 0);
            if(cnt != 0){
                ans = ans|(1<<d);
            }
        }
        return ans;
    }
};

// Solution 2 -- O(n) time and O(1) space
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        for(int i = 0; i < n; i++){
            ans = ans^i^nums[i];
        }
        return ans;
    }
};
