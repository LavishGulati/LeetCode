class Solution {
public:
    int hammingDistance(int x, int y) {
        x = x^y;
        int ans = 0;
        while(x != 0){
            if(x&1){
                ans++;
            }
            x >>= 1;
        }
        return ans;
    }
};
