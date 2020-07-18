#define f first
#define s second
#define pb push_back

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> mp;
        int n = s.length();
        string temp;
        for(int i = 0; i <= n-10; i++){
            temp = s.substr(i, 10);
            mp[temp]++;
        }

        vector<string> output;
        for(auto p : mp){
            if(p.s > 1){
                output.pb(p.f);
            }
        }
        return output;
    }
};
