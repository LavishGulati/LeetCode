class Solution {
public:
    int divide(int dividend, int divisor) {
        bool minus = false;
        if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)){
            minus = true;
        }

        if(dividend == 0){
            return 0;
        }
        if(divisor == 1){
            return min(0LL+dividend, 0LL+INT_MAX);
        }
        else if(divisor == -1){
            return min(0LL-dividend, 0LL+INT_MAX);
        }
        else if(divisor == INT_MIN){
            if(dividend > INT_MIN){
                return 0;
            }
            else{
                return 1;
            }
        }

        int ans = 0;
        if(dividend == INT_MIN){
            if(minus){
                dividend += divisor;
            }
            else{
                dividend -= divisor;
            }
            ans++;
        }

        dividend = abs(dividend);
        divisor = abs(divisor);
        while(dividend >= divisor){
            dividend -= divisor;
            if(ans < INT_MAX){
                ans++;
            }
            else{
                break;
            }
        }

        if(!minus){
            return ans;
        }
        else{
            return -ans;
        }
    }
};
