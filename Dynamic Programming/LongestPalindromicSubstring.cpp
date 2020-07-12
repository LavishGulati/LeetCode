class Solution {
public:
    string longestPalindrome(string s) {
        string out = "";
        int n = s.length();
        for(int i = 0; i < n; i++){
            int j = 0;
            while(i-j >= 0 && i+j < n && s[i-j] == s[i+j]){
                j++;
            }
            j--;
            if(2*j+1 > out.length()){
                out = s.substr(i-j, 2*j+1);
            }
        }
        
        for(int i = 0; i < n-1; i++){
            if(s[i] == s[i+1]){
                int j = 1;
                while(i-j >= 0 && i+1+j < n && s[i-j] == s[i+1+j]){
                    j++;
                }
                j--;
                if(2*j+2 > out.length()){
                    out = s.substr(i-j, 2*j+2);
                }
            }
        }
        return out;
    }
};