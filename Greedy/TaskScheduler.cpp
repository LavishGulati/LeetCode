typedef pair<int, int> pii;
#define mp make_pair
#define f first
#define s second
#define umap unordered_map

class Solution {
public:
    int leastInterval(vector<char>& tasks, int x) {
        priority_queue<pii> pq;
        umap<char, int> freq;
        int n = tasks.size();
        for(int i = 0; i < n; i++){
            freq[tasks[i]]++;
        }

        for(auto p : freq){
            pq.push(mp(p.s, p.f));
        }

        int ans = 0, j = 0;
        vector<pii> cooldown(x+2);
        for(int i = 0; i < x+2; i++){
            cooldown[i] = mp(-1, -1);
        }
        int num = 0;

        while(1){
            if(cooldown[j].f != -1){
                pq.push(cooldown[j]);
                cooldown[j] = mp(-1, -1);
                num--;
            }

            if(!pq.empty()){
                pii p1 = pq.top();
                pq.pop();
                ans++;
                if(p1.f > 1){
                    cooldown[(j+x+1)%(x+2)] = mp(p1.f-1, p1.s);
                    num++;
                }
            }
            else if(num > 0){
                ans++;
            }
            else{
                break;
            }

            j = (j+1)%(x+2);
        }
        return ans;
    }
};
