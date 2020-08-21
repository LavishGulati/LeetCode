class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }

        int n = s.length();

        int freq1[26];
        for(int i = 0; i < 26; i++){
            freq1[i] = 0;
        }
        for(int i = 0; i < n; i++){
            freq1[s[i]-'a']++;
        }

        int freq2[26];
        for(int i = 0; i < 26; i++){
            freq2[i] = 0;
        }
        for(int i = 0; i < n; i++){
            freq2[t[i]-'a']++;
        }

        for(int i = 0; i < 26; i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }
};
