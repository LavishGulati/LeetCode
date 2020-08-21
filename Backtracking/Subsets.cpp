#define pb push_back

class Solution {
public:
    set<vector<int> > dist;

    void subsets(int id, vector<int> &nums, vector<int> &temp){
        if(id == nums.size()){
            dist.insert(temp);
            return;
        }

        subsets(id+1, nums, temp);
        temp.pb(nums[id]);
        subsets(id+1, nums, temp);
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dist.clear();
        vector<int> temp;
        subsets(0, nums, temp);

        vector<vector<int>> output;
        for(auto v : dist){
            output.pb(v);
        }
        return output;
    }
};
