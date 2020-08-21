class Solution {
public:
    bool isPowerOfFour(int num) {
        int cnt = 0;
        while(num > 0 && cnt < 2){
            if(num&2){
                return false;
            }
            if(num&1){
                cnt++;
            }
            num >>= 2;
        }
        if(cnt == 1){
            return true;
        }
        else{
            return false;
        }
    }
};
