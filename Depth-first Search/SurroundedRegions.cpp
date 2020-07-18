class Solution {
public:
    int moveX[4] = {1, -1, 0, 0};
    int moveY[4] = {0, 0, 1, -1};
    bool isSurrounded;

    void surrounded(vector<vector<char>>& board, int i, int j, int n, int m){
        board[i][j] = '.';
        for(int k = 0; k < 4; k++){
            if(i+moveX[k] < 0 || i+moveX[k] >= n || j+moveY[k] < 0 || j+moveY[k] >= m){
                isSurrounded = false;
            }
            else if(board[i+moveX[k]][j+moveY[k]] == 'O'){
                surrounded(board, i+moveX[k], j+moveY[k], n, m);
            }
        }
    }

    void capture(vector<vector<char>>& board, int i, int j, int n, int m){
        board[i][j] = 'X';

        for(int k = 0; k < 4; k++){
            if(board[i+moveX[k]][j+moveY[k]] == '.'){
                capture(board, i+moveX[k], j+moveY[k], n, m);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n == 0){
            return;
        }
        int m = board[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O'){
                    isSurrounded = true;
                    surrounded(board, i, j, n, m);
                    if(isSurrounded){
                        capture(board, i, j, n, m);
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == '.'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
