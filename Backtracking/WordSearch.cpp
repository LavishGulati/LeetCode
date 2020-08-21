class Solution {
public:
    int moveX[4] = {1, -1, 0, 0};
    int moveY[4] = {0, 0, -1, 1};

    bool exist(int x, int y, int id, vector<vector<char>>& board, string &word, bool **visited){
        if(id == word.length()){
            return true;
        }

        int u, v;
        for(int i = 0; i < 4; i++){
            u = x+moveX[i];
            v = y+moveY[i];
            if(u >= 0 && u < board.size() && v >= 0 && v < board[0].size() && board[u][v] == word[id] && !visited[u][v]){
                visited[u][v] = true;
                if(exist(u, v, id+1, board, word, visited)){
                    return true;
                }
                visited[u][v] = false;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        bool **visited = new bool *[n];
        for(int i = 0; i < n; i++){
            visited[i] = new bool[m];
            for(int j = 0; j < m; j++){
                visited[i][j] = false;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0]){
                    visited[i][j] = true;
                    if(exist(i, j, 1, board, word, visited)){
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};
