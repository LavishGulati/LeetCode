#define pb push_back
#define s second
#define f first
#define umap unordered_map

class Solution {
public:
    string calculate(string &s){
        int freq[26];
        for(int i = 0; i < 26; i++){
            freq[i] = 0;
        }
        int n = s.length();
        for(int i = 0; i < n; i++){
            freq[s[i]-'a']++;
        }

        string output = "";
        for(int i = 0; i < 26; i++){
            output += to_string(freq[i])+'#';
        }
        return output;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        umap<string, vector<string>> mp;
        int n = strs.size();
        for(int i = 0; i < n; i++){
            string freq = calculate(strs[i]);
            mp[freq].pb(strs[i]);
        }

        vector< vector<string> > output;
        for(auto p : mp){
            output.pb(p.s);
        }
        return output;
    }
};
