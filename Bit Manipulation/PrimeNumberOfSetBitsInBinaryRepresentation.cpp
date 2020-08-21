class Solution {
public:
    set<int> primes = {2,3,5,7,11,13,17,19,23,29,31};

    int countBits(int x){
        int ans = 0;
        while(x > 0){
            if(x&1){
                ans++;
            }
            x >>= 1;
        }
        return ans;
    }

    int countPrimeSetBits(int L, int R) {
        int ans = 0;
        for(int i = L; i <= R; i++){
            if(primes.find(countBits(i)) != primes.end()){
                ans++;
            }
        }
       return ans;
    }
};
