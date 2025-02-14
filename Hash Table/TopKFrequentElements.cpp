typedef pair<int, int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == n){
            vector<int> output;
            for(int i = 0; i < n; i++){
                output.pb(nums[i]);
            }
            return output;
        }

        unordered_map<int, int> freq;
        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
        }

        priority_queue<pii, vector<pii>, greater<pii> > pq;
        for(pii p : freq){
            if(pq.size() < k){
                pq.push(mp(p.s, p.f));
            }
            else if(p.s > pq.top().f){
                pq.pop();
                pq.push(mp(p.s, p.f));
            }
        }

        vector<int> output;
        while(!pq.empty()){
            output.pb(pq.top().s);
            pq.pop();
        }
        return output;
    }
};
