#define pb push_back

class Solution {
public:
    vector<vector<int> > output;

    void combine(int last, int n, int k, vector<int> &temp){
        if(temp.size() == k){
            output.pb(temp);
            return;
        }

        for(int i = last+1; i <= n; i++){
            temp.pb(i);
            combine(i, n, k, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        output.clear();
        combine(0, n, k, temp);
        return output;
    }
};
