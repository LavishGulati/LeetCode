class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> st;
        for(int i = 0; i < 9; i++){
            st.clear();
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(st.find(board[i][j]) == st.end()){
                        st.insert(board[i][j]);
                    }
                    else{
                        return false;
                    }
                }
            }
        }

        for(int j = 0; j < 9; j++){
            st.clear();
            for(int i = 0; i < 9; i++){
                if(board[i][j] != '.'){
                    if(st.find(board[i][j]) == st.end()){
                        st.insert(board[i][j]);
                    }
                    else{
                        return false;
                    }
                }
            }
        }

        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3){
                st.clear();
                for(int k = 0; k < 3; k++){
                    for(int l = 0; l < 3; l++){
                        if(board[i+k][j+l] != '.'){
                            if(st.find(board[i+k][j+l]) == st.end()){
                                st.insert(board[i+k][j+l]);
                            }
                            else{
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
