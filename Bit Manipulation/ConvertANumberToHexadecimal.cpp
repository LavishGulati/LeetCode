#define all(x) x.begin(), x.end()
typedef unsigned int uint;

class Solution {
public:
    string toHex(int num) {
        uint help = (1<<31);
        help <<= 1;
        if(num < 0){
            num = help+num;
        }

        string ans = "";
        int x;
        char c;
        for(int i = 0; i < 32; i += 4){
            x = num&(15);
            if(x > 9){
                c = 'a'+x-10;
            }
            else{
                c = '0'+x;
            }
            ans += c;
            num >>= 4;
        }
        reverse(all(ans));
        int id = 0;
        while(id < 8){
            if(ans[id] != '0'){
                break;
            }
            id++;
        }
        if(id == 8){
            return "0";
        }
        return ans.substr(id);
    }
};
