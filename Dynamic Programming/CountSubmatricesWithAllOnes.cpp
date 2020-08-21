class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        if(n == 0){
            return 0;
        }
        int m = mat[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 1; j < m; j++){
                if(mat[i][j] == 1){
                    mat[i][j] += mat[i][j-1];
                }
            }
        }

        int sum, x;
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < m; j++){
                if(mat[i][j] > 0){
                    sum = 0, x = mat[i][j];
                    for(int k = i-1; k >= 0 && mat[k][j] > 0; k--){
                        x = min(mat[k][j], x);
                        sum += min(x, mat[k][j]);
                    }
                    mat[i][j] += sum;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans += mat[i][j];
            }
            cout << endl;
        }
        return ans;
    }
};
