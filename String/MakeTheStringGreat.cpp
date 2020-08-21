class Solution {
public:
    string makeGood(string s) {
        int n = s.length();
        stack<char> st;
        for(int i = n-1; i >= 0; i--){
            if(st.empty()){
                st.push(s[i]);
            }
            else if(abs(s[i]-st.top()) == abs('a'-'A')){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
