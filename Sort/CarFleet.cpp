typedef pair<int, int> pii;
#define mp make_pair
#define f first
#define s second

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if(n == 0){
            return 0;
        }

        pii *a = new pii[n];
        for(int i = 0; i < n; i++){
            a[i] = mp(position[i], speed[i]);
        }

        sort(a, a+n);
        int ans = 1;
        int nextFleet = n-1;
        for(int i = n-2; i >= 0; i--){
            if(a[i].s > a[nextFleet].s && (a[nextFleet].f-a[i].f)/double(a[i].s-a[nextFleet].s) <= (target-a[nextFleet].f)/double(a[nextFleet].s)){
                // do nothing
            }
            else{
                nextFleet = i;
                ans++;
            }
        }
        return ans;
    }
};
