class Solution {
public:
    char findTheDifference(string s, string t) {
        int num1 = 0;
        for(char c : s){
            num1 = num1^(1<<(c-'a'));
        }

        int num2 = 0;
        for(char c : t){
            num2 = num2^(1<<(c-'a'));
        }

        int ans = num1^num2;
        int i = 0;
        while(1){
            if(ans&1){
                return 'a'+i;
            }
            i++; ans >>= 1;
        }
    }
};
