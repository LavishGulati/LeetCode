class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& a) {
        int n = a.size();
        int i = 0, j = 1;
        while(i < n && j < n){
            while(i < n && !(a[i]%2)){
                i += 2;
            }
            while(j < n && (a[j]%2)){
                j += 2;
            }

            if(i < n && j < n){
                swap(a[i], a[j]);
                i += 2; j += 2;
            }
        }
        return a;
    }
};
