#define all(x) x.begin(), x.end()
#define pb push_back

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> temp;
        vector< vector<string> > output;

        int n = strs.size();
        for(int i = 0; i < n; i++){
            string s = strs[i];
            sort(all(s));
            if(temp.find(s) == temp.end()){
                temp[s] = output.size();
                vector<string> v;
                v.pb(strs[i]);
                output.pb(v);
            }
            else{
                output[temp[s]].pb(strs[i]);
            }
        }
        return output;
    }
};
