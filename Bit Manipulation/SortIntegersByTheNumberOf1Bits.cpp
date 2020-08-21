#define all(x) x.begin(), x.end()
#define pb push_back

int countBits(int x){
    int ans = 0;
    while(x > 0){
        if(x&1){
            ans++;
        }
        x >>= 1;
    }
    return ans;
}

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> output;

        vector<int> help[32];
        for(int i = 0; i < arr.size(); i++){
            int b = countBits(arr[i]);
            help[b].pb(arr[i]);
        }
        for(int i = 0; i < 32; i++){
            sort(all(help[i]));
            for(int x : help[i]){
                output.pb(x);
            }
        }
        return output;
    }
};
