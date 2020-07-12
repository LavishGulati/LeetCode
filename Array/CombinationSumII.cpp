#define all(x) x.begin(), x.end()
#define pb push_back

class Solution {
public:
    set< vector<int> > helper;
    vector<int> v;
    
    void solve(vector<int> &candidates, int id, int n, int target){
        if(id == n){
            if(target == 0){
                helper.insert(v);
            }
            return;
        }
        
        if(target < 0){
            return;
        }
        else if(target == 0){
            helper.insert(v);
            return;
        }
        
        v.pb(candidates[id]);
        solve(candidates, id+1, n, target-candidates[id]);
        v.pop_back();
        
        solve(candidates, id+1, n, target);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(all(candidates));
        helper.clear();
        v.clear();
        
        solve(candidates, 0, n, target);
        vector< vector<int> > output;
        for(auto x : helper){
            output.pb(x);
        }
        return output;
    }
};