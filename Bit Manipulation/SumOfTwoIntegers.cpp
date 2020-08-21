class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0, ans = 0, help = 1;

        while(a || b || carry){
            if((a&(1)) && (b&(1))){
                if(carry){
                    ans = (ans|help);
                }
                carry = 1;
            }
            else if(!(a&(1)) && !(b&(1))){
                if(carry){
                    ans = (ans|help);
                }
                carry = 0;
            }
            else{
                if(!carry){
                    ans = (ans|help);
                    carry = 0;
                }
                else{
                    carry = 1;
                }
            }
            a >>= 1;
            b >>= 1;
            if(help < 0){
                break;
            }
            else{
                help <<= 1;
            }
        }
        return ans;
    }
};
