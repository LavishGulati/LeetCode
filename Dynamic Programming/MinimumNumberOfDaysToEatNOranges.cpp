class Solution {
public:
    map<int, int> mp;

    int minDays(int n) {
        if(n <= 1){
            return n;
        }

        if(mp.find(n) == mp.end()){
            mp[n] = 1+min(n%2+minDays(n/2), n%3+minDays(n/3));
        }
        return mp[n];
    }
};
