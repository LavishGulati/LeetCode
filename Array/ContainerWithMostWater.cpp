typedef pair<int, int> pii;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

pii binary_search(vector<pii> &v, int i, int j, int x){
    int si = i;
    int ei = j;
    pii ans = mp(-1, -1);
    while(si <= ei){
        int mid = (si+ei)/2;
        if(v[mid].s < x){
            si = mid+1;
        }
        else{
            ans = v[mid];
            ei = mid-1;
        }
    }
    return ans;
}

int solve(vector<int> &height){
    vector<pii> help;
    int n = height.size();
    for(int i = 0; i < n; i++){
        if(help.size() == 0 || (height[i] > help[help.size()-1].s)){
            help.pb(mp(i, height[i]));
        }
    }

    int ans = 0;
    int j = 0;
    for(int i = 0; i < n; i++){
        pii x = mp(i, height[i]);
        while(j < help.size() && help[j].f <= i){
            j++;
        }
        pii y = binary_search(help, 0, j-1, x.s);
        if(y.f != -1){
            x = y;
        }

        ans = max(ans, height[i]*(i-x.f));
    }
    
    return ans;
}

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = solve(height);
        
        reverse(all(height));
        ans = max(ans, solve(height));
        
        return ans;
    }
};