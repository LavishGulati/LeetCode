typedef pair<int, int> pii;
#define mp make_pair
#define f first
#define s second
#define pb push_back

int moveX[4] = {1, -1, 0, 0};
int moveY[4] = {0, 0, -1, 1};

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> output;
        vector<int> v;
        queue<pii> q[2];
        int id = 0;

        bool **done = new bool *[R];
        for(int i = 0; i < R; i++){
            done[i] = new bool[C];
            for(int j = 0; j < C; j++){
                done[i][j] = false;
            }
        }

        q[0].push(mp(r0, c0));
        done[r0][c0] = true;
        v.pb(r0);
        v.pb(c0);
        output.pb(v);

        pii u;
        int a, b;
        while(!q[id].empty()){
            while(!q[id].empty()){
                u = q[id].front();
                q[id].pop();
                for(int i = 0; i < 4; i++){
                    a = u.f+moveX[i];
                    b = u.s+moveY[i];
                    if(a >= 0 && a < R && b >= 0 && b < C && !done[a][b]){
                        q[id^1].push(mp(a, b));
                        done[a][b] = true;
                        v.clear();
                        v.pb(a);
                        v.pb(b);
                        output.pb(v);
                    }
                }
            }
            id ^= 1;
        }
        return output;
    }
};
