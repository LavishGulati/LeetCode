#define MAX 100005
#define MOD 1000000007
typedef long long ll;
#define pb push_back
#define all(x) x.begin(), x.end()

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        ll *v = new ll[MAX];
        for(ll i = 0; i < MAX; i++){
            v[i] = 0;
        }

        ll sum, cnt;
        for(ll i = 0; i < n; i++){
            sum = 0;
            for(ll j = i; j < n; j++){
                sum += nums[j];
                v[sum]++;
            }
        }

        sum = 0, cnt = 0;
        for(ll i = 0; i < MAX; i++){
            if(cnt > right){
                break;
            }
            else if(cnt+v[i] < left){
                cnt += v[i];
            }
            else if(cnt < left){
                sum = (sum+(min(cnt+v[i]-left+1, ll(right-left+1))*i)%MOD)%MOD;
                cnt += v[i];
            }
            else{
                sum = (sum+(min(right-cnt, v[i])*i)%MOD)%MOD;
                cnt += v[i];
            }
        }

        return sum;
    }
};
