#define all(x) x.begin(), x.end()

class Solution {
public:
    string simplifyPath(string path) {
        string curWord = "";
        int n = path.length();
        stack<string> st;
        for(int i = 0; i < n; i++){
            if(path[i] == '/'){
                if(curWord.length() > 0){
                    st.push(curWord);
                    curWord = "";
                }
            }
            else if(path[i] == '.'){
                if(curWord.length() > 0){
                    st.push(curWord);
                    curWord = "";
                }

                int j = i+1;
                while(j < n && path[j] == '.'){
                    j++;
                }
                if(j-i == 2 && (j == n || path[j] == '/')){
                    if(!st.empty()){
                        st.pop();
                    }
                    i++;
                }
                else if((j-i > 2) || (j < n && path[j] != '/')){
                    for(int k = 0; k < j-i; k++){
                        curWord += '.';
                    }
                    i = j-1;
                }
            }
            else{
                curWord += path[i];
            }
        }
        if(curWord.length() > 0){
            st.push(curWord);
            curWord = "";
        }

        stack<string> help;
        while(!st.empty()){
            help.push(st.top());
            st.pop();
        }

        string output = "";
        while(!help.empty()){
            output += '/';
            output += help.top();
            help.pop();
        }
        if(output.length() == 0){
            output = "/";
        }

        return output;
    }
};
