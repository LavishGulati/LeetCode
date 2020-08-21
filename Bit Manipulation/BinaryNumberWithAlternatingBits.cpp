class Solution {
public:
    bool hasAlternatingBits(int n) {
        while(n > 0){
            if((n&1) && (n&2)){
                return false;
            }
            else if(!(n&1) && !(n&2)){
                return false;
            }

            n >>= 1;
        }
        return true;
    }
};
