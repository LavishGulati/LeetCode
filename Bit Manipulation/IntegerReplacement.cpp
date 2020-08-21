class Solution {
public:
    int integerReplacement(int n) {
        if(n == INT_MAX){
            return 32;
        }

        int ans = 0;
        int num, x;
        while(n > 1){
            if(n&1){
                x = n; num = 0;
                while(x&1){
                    num++;
                    x >>= 1;
                }

                if((n^((1<<num)-1)) == 0 && num < 4){
                    ans += 2*(num-1);
                    n >>= num;
                }
                else if((n^((1<<num)-1)) != 0 && num == 1){
                    ans += 2;
                    n >>= 1;
                }
                else{
                    ans += num+1;
                    n = n|(1<<num);
                    n >>= num;
                }
            }
            else{
                ans++;
                n >>= 1;
            }
        }
        return ans;
    }
};
