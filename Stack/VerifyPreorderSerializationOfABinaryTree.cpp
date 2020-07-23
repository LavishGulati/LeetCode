typedef pair<int, bool> pib;
#define mp make_pair
#define f first
#define s second

class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder == "#"){
            return true;
        }

        stack<pib> st;
        preorder += ',';
        int n = preorder.length();
        string curWord = "";
        int num = 0;
        for(int i = 0; i < n; i++){
            if(preorder[i] == ','){
                if(curWord == "#"){
                    if(st.empty()){
                        return false;
                    }

                    while(!st.empty()){
                        pib p = st.top();
                        st.pop();
                        if(!p.s){
                            p.s = true;
                            st.push(p);
                            break;
                        }
                    }

                    if(st.empty()){
                        num++;
                    }
                }
                else{
                    st.push(mp(stoi(curWord), false));
                }
                curWord = "";
            }
            else{
                curWord += preorder[i];
            }
        }

        if(num == 1 && st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
