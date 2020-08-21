// Solution 1 -- O(nlogn) time and O(1) space

#define all(x) x.begin(), x.end()
#define pb push_back

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(all(nums));
        int sum = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        int s = 0;
        vector<int> output;
        for(int i = n-1; i >= 0; i--){
            s += nums[i];
            sum -= nums[i];
            output.pb(nums[i]);
            if(s > sum){
                return output;
            }
        }
        return output;
    }
};

// Solution 2 -- O(MAX+n) time and O(MAX) space
#define pb push_back

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int *count = new int[101];
        for(int i = 0; i < 101; i++){
            count[i] = 0;
        }

        int sum = 0, n = nums.size(), s = 0;
        for(int i = n-1; i >= 0; i--){
            count[nums[i]]++;
            sum += nums[i];
        }

        vector<int> output;
        for(int i = 100; i >= 0; i--){
            while(count[i] > 0){
                s += i;
                sum -= i;
                count[i]--;
                output.pb(i);
                if(s > sum){
                    return output;
                }
            }
        }
        return output;
    }
};
