class Solution {
public:
    bool isPowerOfTwo(int n) {
        int num = 0;
        while(n > 0 && num < 2){
            if(n&1){
                num++;
            }
            n >>= 1;
        }
        if(num == 1){
            return true;
        }
        else{
            return false;
        }
    }
};
