#define pb push_back

class Solution {
public:
    vector<string> output;

    void solve(int id, string &S, string x){
        if(id == S.length()){
            output.pb(x);
            return;
        }

        if(S[id] >= '0' && S[id] <= '9'){
            solve(id+1, S, x+S[id]);
        }
        else{
            char c = S[id];
            solve(id+1, S, x+c);
            if(c >= 'A' && c <= 'Z'){
                c = c-'A'+'a';
            }
            else{
                c = c-'a'+'A';
            }
            solve(id+1, S, x+c);
        }
    }

    vector<string> letterCasePermutation(string S) {
        output.clear();
        solve(0, S, "");
        return output;
    }
};
