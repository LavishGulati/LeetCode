#define pb push_back

class Solution {
public:
    vector<string> output;

    void generateParenthesis(int si, int ei, int diff, string ans){
        if(si == 0 && ei == 0){
            if(ans.length() > 0){
                output.pb(ans);
            }
            return;
        }
        else if(si == 0){
            generateParenthesis(si, ei-1, diff-1, ans+')');
        }
        else if(diff > 0){
            generateParenthesis(si-1, ei, diff+1, ans+'(');
            generateParenthesis(si, ei-1, diff-1, ans+')');
        }
        else{
            generateParenthesis(si-1, ei, diff+1, ans+'(');
        }
    }

    vector<string> generateParenthesis(int n) {
        output.clear();
        generateParenthesis(n, n, 0, "");
        return output;
    }
};
