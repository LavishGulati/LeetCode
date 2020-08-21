#define all(x) x.begin(), x.end()

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 4){
            return 0;
        }

        priority_queue<int> pq1;
        for(int i = 0; i < 4; i++){
            pq1.push(nums[i]);
        }
        for(int i = 4; i < n; i++){
            if(pq1.top() > nums[i]){
                pq1.pop();
                pq1.push(nums[i]);
            }
        }
        int small[4];
        for(int i = 3; i >= 0; i--){
            small[i] = pq1.top();
            pq1.pop();
        }

        priority_queue<int, vector<int>, greater<int>> pq2;
        for(int i = 0; i < 4; i++){
            pq2.push(nums[i]);
        }
        for(int i = 4; i < n; i++){
            if(pq2.top() < nums[i]){
                pq2.pop();
                pq2.push(nums[i]);
            }
        }
        int large[4];
        for(int i = 0; i < 4; i++){
            large[i] = pq2.top();
            pq2.pop();
        }

        int ans = INT_MAX;
        for(int i = 0; i <= 3; i++){
            int j = 3-i;
            ans = min(ans, large[4-j-1]-small[i]);
        }
        return ans;
    }
};
