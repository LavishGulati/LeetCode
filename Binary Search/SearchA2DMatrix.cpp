class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0){
            return false;
        }
        int m = matrix[0].size();
        if(m == 0){
            return false;
        }

        int si = 0, ei = n-1, mid, mid2;
        while(si <= ei){
            mid = (si+ei)/2;
            if(target < matrix[mid][0]){
                ei = mid-1;
            }
            else if(target > matrix[mid][m-1]){
                si = mid+1;
            }
            else{
                break;
            }
        }

        si = 0, ei = m-1, mid2;
        while(si <= ei){
            mid2 = (si+ei)/2;
            if(target < matrix[mid][mid2]){
                ei = mid2-1;
            }
            else if(target > matrix[mid][mid2]){
                si = mid2+1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
