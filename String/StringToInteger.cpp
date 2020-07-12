typedef long long ll;

class Solution {
public:
    int myAtoi(string s) {
        ll n = s.length();
        ll i = 0;
        while(i < n && s[i] == ' '){
            i++;
        }

        if(i >= n){
            return 0;
        }

        bool minus = false;
        if(s[i] == '-'){
            minus = true;
            i++;
        }
        else if(s[i] == '+'){
            i++;
        }

        ll num = 0;
        while(i < n && s[i] >= '0' && s[i] <= '9'){
            num = 10*num+(s[i]-'0');
            if(num > INT_MAX){
                break;
            }
            i++;
        }

        if(num > INT_MAX && minus){
            return INT_MIN;
        }
        else if(num > INT_MAX){
            return INT_MAX;
        }
        else if(minus){
            return (-1)*num;
        }
        else{
            return num;
        }
    }
};
