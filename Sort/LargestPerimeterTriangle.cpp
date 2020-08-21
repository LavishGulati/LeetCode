#define all(x) x.begin(), x.end()

class Solution {
public:
    int largestPerimeter(vector<int>& a) {
        sort(all(a));
        int n = a.size();
        for(int i = n-1; i >= 2; i--){
            if(a[i-2]+a[i-1] > a[i]){
                return a[i-2]+a[i-1]+a[i];
            }
        }
        return 0;
    }
};
