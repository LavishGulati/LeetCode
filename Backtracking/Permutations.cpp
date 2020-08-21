#define all(x) x.begin(), x.end()
#define pb push_back

class Solution {
public:
    vector<vector<int>> output;

    void permute(vector<int> &nums, vector<int> &help, bool *taken){
        if(help.size() == nums.size()){
            output.pb(help);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(!taken[i]){
                taken[i] = true;
                help.pb(nums[i]);
                permute(nums, help, taken);
                taken[i] = false;
                help.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> help;
        output.clear();
        bool *taken = new bool[nums.size()];
        for(int i = 0; i < nums.size(); i++){
            taken[i] = false;
        }
        permute(nums, help, taken);
        return output;
    }
};
