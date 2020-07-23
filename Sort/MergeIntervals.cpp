#define all(x) x.begin(), x.end()
#define pb push_back

bool compare(vector<int> &a, vector<int> &b){
    if(a[0] != b[0]){
        return a[0] < b[0];
    }
    else{
        return a[1] < b[1];
    }
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(all(intervals), compare);

        vector< vector<int> > output;
        for(int i = 0; i < n; i++){
            if(output.size() == 0){
                output.pb(intervals[i]);
            }
            else if(intervals[i][0] > output.back()[1]){
                output.pb(intervals[i]);
            }
            else{
                output.back()[1] = max(intervals[i][1], output.back()[1]);
            }
        }
        return output;
    }
};
