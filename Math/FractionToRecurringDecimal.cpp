typedef long long ll;

class Solution {
public:
    string fractionToDecimal(int numer, int denom) {
        ll num = ll(numer);
        ll den = ll(denom);
        string intpart = "";
        if((num < 0 && den > 0) || (num > 0 && den < 0)){
            intpart += '-';
        }
        num = abs(num);
        den = abs(den);
        intpart += to_string(num/den);
        num -= (num/den)*den;

        string frac = "";
        map<int, int> id;
        while(num > 0){
            num *= 10;
            if(id.find(num) == id.end()){
                id[num] = frac.length();
                frac += string(1, '0'+(num/den));
                num -= (num/den)*den;
            }
            else{
                int l = id[num];
                return intpart+'.'+frac.substr(0, l)+'('+frac.substr(l)+')';
            }
        }
        if(frac.length() == 0){
            return intpart;
        }
        else{
            return intpart+'.'+frac;
        }
    }
};
