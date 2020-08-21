// Solution 1 -- O(n) time and O(1) space
class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = (ans^(start+2*i));
        }
        return ans;
    }
};

// Solution 2 -- O(1) time and O(1) space
class Solution {
public:
    int xorFrom0ToN(int n){
        if(n%4 == 0){
            return n;
        }
        else if(n%4 == 1){
            return 1;
        }
        else if(n%4 == 2){
            return n+1;
        }
        else{
            return 0;
        }
    }

    int xorInRange(int a, int b){
        return xorFrom0ToN(a)^xorFrom0ToN(b)^a;
    }

    int xorOperation(int n, int start) {
        int ans = xorInRange(start/2, start/2 + (n-1));
        ans <<= 1;
        if((start&1) && (n&1)){
            ans = ans^1;
        }
        return ans;
    }
};
