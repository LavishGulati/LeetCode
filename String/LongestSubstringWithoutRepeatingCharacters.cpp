#define uset unordered_set

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, n = s.length();
        int ans = 0;
        uset<char> present;

        while(j < n){
            if(present.find(s[j]) == present.end()){
                present.insert(s[j]);
                j++;
            }
            else{
                ans = max(ans, j-i);
                while(s[i] != s[j]){
                    present.erase(s[i]);
                    i++;
                }
                i++; j++;
            }
        }
        ans = max(ans, j-i);
        return ans;
    }
};
