class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == 0){
            return 0;
        }

        int help = 1, ans = 0;
        for(int i = 0; i < 30; i++){
            if(n-m+1 >= help+1){
                // do nothing
            }
            else{
                if(m&(1<<i) && n&(1<<i)){
                    ans = (ans|(1<<i));
                }
            }
            help *= 2;
        }
        if(m&(1<<30) && n&(1<<30)){
            ans = (ans|(1<<30));
        }
        return ans;
    }
};
