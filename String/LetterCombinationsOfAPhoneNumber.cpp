#define pb push_back

class Solution {
public:
    map<int, string> temp;
    vector<string> output;

    Solution(){
        temp[2] = "abc";
        temp[3] = "def";
        temp[4] = "ghi";
        temp[5] = "jkl";
        temp[6] = "mno";
        temp[7] = "pqrs";
        temp[8] = "tuv";
        temp[9] = "wxyz";
    }

    void letterCombinations(string s, int id, int n, string ans){
        if(id >= n){
            if(ans.length() > 0){
                output.pb(ans);
            }
            return;
        }

        for(int i = 0; i < temp[s[id]-'0'].length(); i++){
            letterCombinations(s, id+1, n, ans+temp[s[id]-'0'][i]);
        }
    }

    vector<string> letterCombinations(string digits) {
        output.clear();

        letterCombinations(digits, 0, digits.length(), "");
        return output;
    }
};
