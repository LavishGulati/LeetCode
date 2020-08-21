#define pb push_back

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for(int i = 0; i < n; i++){
            x = (x^nums[i]);
        }

        int b = -1;
        for(int i = 0; i < 32; i++){
            if(x&(1<<i)){
                b = i;
                break;
            }
        }

        int first = 0;
        for(int i = 0; i < n; i++){
            if(nums[i]&(1<<b)){
                first = first^nums[i];
            }
        }

        vector<int> output;
        output.pb(first);
        output.pb(x^first);
        return output;
    }
};
