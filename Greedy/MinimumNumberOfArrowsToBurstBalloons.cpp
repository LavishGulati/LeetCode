typedef pair<int, bool> pib;
#define f first
#define s second
#define mp make_pair

struct Query{
    int val, id;
    bool isStart;

    Query(){

    }

    Query(int v, int i, bool s){
        val = v, id = i;
        isStart = s;
    }
};

bool compare(Query a, Query b){
    if(a.val != b.val){
        return a.val < b.val;
    }
    else if(a.isStart){
        return true;
    }
    else{
        return false;
    }
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        Query *a = new Query[2*n];
        for(int i = 0; i < n; i++){
            a[2*i] = Query(points[i][0], i, true);
            a[2*i+1] = Query(points[i][1], i, false);
        }

        sort(a, a+2*n, compare);
        int ans = 0, num = 0;
        bool *done = new bool[n];
        for(int i = 0; i < n; i++){
            done[i] = false;
        }
        set<int> curr;
        for(int i = 0; i < 2*n; i++){
            if(a[i].isStart){
                curr.insert(a[i].id);
            }
            else if(!done[a[i].id]){
                if(curr.size() > 0){
                    ans++;
                    for(int x : curr){
                        done[x] = true;
                    }
                    curr.clear();
                }
            }
        }

        return ans;
    }
};
