#define all(x) x.begin(), x.end()

bool compare(vector<int> &a, vector<int> &b){
    if(a[1] != b[1]){
        return a[1] < b[1];
    }
    else{
        return a[0] > b[0];
    }
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(all(intervals), compare);
        int num = 0, over = INT_MIN;
        for(int i = 0; i < n; i++){
            if(intervals[i][0] >= over){
                num++;
                over = intervals[i][1];
            }
        }
        return n-num;
    }
};
