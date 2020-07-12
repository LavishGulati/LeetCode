class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int i = 0, j = 0;
        while(i < n/2){
            for(int k = 0; k < n-1-2*i; k++){
                int x = matrix[n-1-k-i][j];
                matrix[n-1-k-i][j] = matrix[n-1-i][n-1-k-j];
                matrix[n-1-i][n-1-k-j] = matrix[k+i][n-1-j];
                matrix[k+i][n-1-j] = matrix[i][k+j];
                matrix[i][k+j] = x;
            }
            
            i++; j++;
        }
    }
};