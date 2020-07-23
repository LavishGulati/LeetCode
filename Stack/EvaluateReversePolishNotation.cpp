class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size(), a, b;
        for(string x : tokens){
            if(x[0] == '+' || (x[0] == '-' && x.length() == 1) || x[0] == '*' || x[0] == '/'){
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                if(x[0] == '+'){
                    st.push(a+b);
                }
                else if(x[0] == '-'){
                    st.push(a-b);
                }
                else if(x[0] == '*'){
                    st.push(a*b);
                }
                else if(x[0] == '/'){
                    st.push(a/b);
                }
            }
            else{
                st.push(stoi(x));
            }
        }
        return st.top();
    }
};
