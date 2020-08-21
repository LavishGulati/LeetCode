class Solution {
public:
    int findComplement(int num) {
        int ans = 0, id = 0;
        while(num > 0){
            if(!(num&1)){
                ans = ans|(1<<id);
            }
            id++;
            num >>= 1;
        }
        return ans;
    }
};
