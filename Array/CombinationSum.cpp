#define pb push_back

class Solution {
public:
    vector< vector<int> > output;
    
    vector<int> help;
    
    void solve(vector<int> &candidates, int id, int n, int target){
        if(id == n){
            if(target == 0){
                output.pb(help);
            }
            return;
        }
        
        if(target < 0){
            return;
        }
        else if(target == 0){
            output.pb(help);
            return;
        }
        
        help.pb(candidates[id]);
        solve(candidates, id, n, target-candidates[id]);
        help.pop_back();
        
        solve(candidates, id+1, n, target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        output.clear();
        help.clear();    
            
        solve(candidates, 0, n, target);
        return output;
    }
};