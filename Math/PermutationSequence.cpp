class Solution {
public:
    int fact[10];

    Solution(){
        fact[0] = 1;
        for(int i = 1; i < 10; i++){
            fact[i] = fact[i-1]*i;
        }
    }

    string getPermutation(int n, int m, int k, bool *taken){
        if(m == 1){
            for(int i = 1; i <= n; i++){
                if(!taken[i]){
                    return string(1, '0'+i);
                }
            }
        }

        int i = 1;
        while(1){
            while(i <= n && taken[i]){
                i++;
            }
            if(k > fact[m-1]){
                k -= fact[m-1];
                i++;
            }
            else{
                taken[i] = true;
                return string(1, '0'+i) + getPermutation(n, m-1, k, taken);
            }
        }
    }

    string getPermutation(int n, int k) {
        bool *taken = new bool[n+1];
        for(int i = 0; i <= n; i++){
            taken[i] = false;
        }

        return getPermutation(n, n, k, taken);
    }
};
