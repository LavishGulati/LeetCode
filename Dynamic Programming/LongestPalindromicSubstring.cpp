class Solution {
public:
    string LPS(string &s){
        int n = s.length();
        if(n == 0){
            return "";
        }

        n = 2*n+1;
        int *lps = new int[n];

        lps[0] = 0;
        lps[1] = 1;
        int c = 1, r = 2, i = 0, iMirror, expand = -1, diff = -1, maxLPSlength = 1;
        int maxLPScenterPosn = 1, start = -1, end = -1;
        for(i = 2; i < n; i++){
            iMirror = 2*c-i;
            expand = 0;
            diff = r-i;
            if(diff >= 0){
                if(lps[iMirror] < diff){
                    lps[i] = lps[iMirror];
                }
                else if(lps[iMirror] == diff && r == n-1){
                    lps[i] = lps[iMirror];
                }
                else if(lps[iMirror] == diff && r < n-1){
                    lps[i] = lps[iMirror];
                    expand = 1;
                }
                else if(lps[iMirror] > diff){
                    lps[i] = diff;
                    expand = 1;
                }
            }
            else{
                lps[i] = 0;
                expand = 1;
            }

            if(expand == 1){
                while(i+lps[i] < n && i-lps[i] > 0 && ((i+lps[i]+1)%2 == 0 || s[(i+lps[i]+1)/2] == s[(i-lps[i]-1)/2])){
                    lps[i]++;
                }
            }

            if(lps[i] > maxLPSlength){
                maxLPSlength = lps[i];
                maxLPScenterPosn = i;
            }

            if(i+lps[i] > r){
                c = i;
                r = i+lps[i];
            }
        }

        start = (maxLPScenterPosn-maxLPSlength)/2;
        end = (start+maxLPSlength-1);
        string output = "";
        for(i = start; i <= end; i++){
            output += s[i];
        }
        return output;
    }

    string longestPalindrome(string s) {
        return LPS(s);
    }
};
