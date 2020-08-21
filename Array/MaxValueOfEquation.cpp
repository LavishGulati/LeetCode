typedef pair<int, int> pii;
#define f first
#define s second
#define mp make_pair

void insert(deque<pii> &dq, pii x){
    while(!dq.empty() && dq.back().f <= x.f){
        dq.pop_back();
    }
    dq.push_back(x);
}

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<pii> dq;
        int ans = INT_MIN, x, j, n = points.size();
        for(j = 1; j < n; j++){
            if(points[j][0] <= points[0][0]+k){
                insert(dq, mp(points[j][0]+points[j][1], j));
            }
            else{
                break;
            }
        }

        for(int i = 0; i < n-1; i++){
            x = points[i][1]-points[i][0];
            while(!dq.empty() && dq.front().s <= i){
                dq.pop_front();
            }
            if(!dq.empty()){
                ans = max(ans, x+dq.front().f);
            }
            while(j < n && points[j][0] <= points[i+1][0]+k){
                insert(dq, mp(points[j][0]+points[j][1], j));
                j++;
            }
        }
        return ans;
    }
};
