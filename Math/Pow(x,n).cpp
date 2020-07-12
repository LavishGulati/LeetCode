class Solution {
public:
    double myPow(double x, int n) {
        if(n == 1){
            return x;
        }
        else if(n == 0){
            return 1;
        }
        else if(n == -1){
            return 1/x;
        }

        double y = myPow(x, n/2);
        if(n > 0){
            if(n%2){
                return (x*y*y);
            }
            else{
                return (y*y);
            }
        }
        else{
            if(n%2){
                return ((1/x)*y*y);
            }
            else{
                return (y*y);
            }
        }
    }
};
