#define MOD 1000000007
typedef long long ll;

class Solution {
public:
    int numSub(string s) {
        ll n = s.length(), cnt, j, ans = 0, x;
        for(ll i = 0; i < n; i++){
            if(s[i] == '1'){
                cnt = 0;
                j = i;
                while(j < n && s[j] == '1'){
                    cnt++;
                    j++;
                }
                x = (cnt*(cnt+1))/2;
                ans = (ans+x)%MOD;
                i = j-1;
            }
        }
        return int(ans);
    }
};
