class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }

        int d = 0, y = x;
        while(y > 0){
            d++;
            y /= 10;
        }

        if(!d){
            return true;
        }

        int power[d];
        power[0] = 1;
        for(int i = 1; i < d; i++){
            power[i] = power[i-1]*10;
        }

        for(int i = 0; i < d/2; i++){
            if((x/power[i])%10 != (x/power[d-i-1])%10){
                return false;
            }
        }
        return true;
    }
};
