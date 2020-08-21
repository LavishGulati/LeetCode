#define pb push_back

class Solution {
public:
    int setbits(int x){
        int ans = 0;
        while(x > 0){
            if(x%2){
                ans++;
            }
            x /= 2;
        }
        return ans;
    }

    int maxProduct(vector<string>& words) {
        int ans = 0;
        int n = words.size(), x;
        vector<int> v;
        for(int i = 0; i < n; i++){
            x = 0;
            for(char c : words[i]){
                x = (x|(1<<(c-'a')));
            }
            v.pb(x);
        }

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int a = setbits(v[i]);
                int b = setbits(v[j]);
                int c = setbits(v[i]^v[j]);
                if(c == a+b){
                    ans = max(ans, int(words[i].length()*words[j].length()));
                }
            }
        }
        return ans;
    }
};
