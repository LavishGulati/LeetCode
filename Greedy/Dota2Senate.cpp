class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        char cur = senate[0];
        int d = 0, r = 0;
        for(int i = 0; i < n; i++){
            if(senate[i] == 'D'){
                d++;
            }
            else{
                r++;
            }
        }

        int num = 1, i = 1;
        while(d > 0 && r > 0){
            if(senate[i] != '.'){
                if(senate[i] == cur){
                    num++;
                }
                else if(num > 0){
                    senate[i] = '.';
                    num--;
                    if(cur == 'D'){
                        r--;
                    }
                    else{
                        d--;
                    }
                }
                else{
                    cur = senate[i];
                    num = 1;
                }
            }
            i = (i+1)%n;
        }

        if(d > 0){
            return "Dire";
        }
        else{
            return "Radiant";
        }
    }
};
