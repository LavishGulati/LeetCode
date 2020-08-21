// Bit Manipulation -- O(n) time and O(1) space
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int cnt;
        for(int d = 31; d >= 0; d--){
            cnt = 0;
            for(int i = 0; i < n; i++){
                if(nums[i]&(1<<d)){
                    cnt++;
                }
            }
            if(cnt > n/2){
                ans = (ans|(1<<d));
            }
        }
        return ans;
    }
};

// Boyer-Moore Voting Algorithm -- O(n) time and O(1) space
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cand = nums[0], freq = 1;
        for(int i = 1; i < n; i++){
            if(freq == 0){
                cand = nums[i];
                freq = 1;
            }
            else if(nums[i] == cand){
                freq++;
            }
            else{
                freq--;
            }
        }
        return cand;
    }
};
