#define all(x) x.begin(), x.end()

class Solution {
public:
    string add(string s1, string s2){
        int n = s1.length(), m = s2.length(), carry = 0;
        int i = n-1, j = m-1;
        string output = "";
        while(i >= 0 || j >= 0){
            int x = 0;
            if(i >= 0){
                x += s1[i]-'0';
                i--;
            }
            if(j >= 0){
                x += s2[j]-'0';
                j--;
            }
            x += carry;
            char c = '0'+(x%10);
            output += c;
            carry = x/10;
        }
        if(carry > 0){
            char c = carry+'0';
            output += c;
        }
        reverse(all(output));
        return output;
    }

    string multiply(string num1, string num2) {
        int m = num2.length();
        int n = num1.length();

        string output = "0";
        for(int i = m-1; i >= 0; i--){
            int carry = 0;
            string help = "";
            for(int j = n-1; j >= 0; j--){
                int x = (num1[j]-'0')*(num2[i]-'0')+carry;
                char c = '0'+(x%10);
                help += c;
                carry = x/10;
            }
            if(carry > 0){
                char c = carry+'0';
                help += c;
            }
            reverse(all(help));
            for(int j = 0; j < m-i-1; j++){
                help += '0';
            }
            output = add(output, help);
            // cout << help << " " << output << endl;
        }
        int i = 0;
        while(i < output.size() && output[i] == '0'){
            i++;
        }
        if(i == output.size()){
            return "0";
        }
        else{
            return output.substr(i);
        }
    }
};
