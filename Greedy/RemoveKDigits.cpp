class Solution {
public:
    string removeKdigits(string num, int k) {
        string output = "";
        int n = num.length();
        if(k == n){
            return "0";
        }

        int i, del = 0;
        for(i = 0; i < n; i++){
            if(del < k && output.length() > 0 && num[i] < output[output.length()-1]){
                int j = output.length()-1;
                while(del < k && j >= 0 && num[i] < output[j]){
                    output[j] = num[i];
                    del++;
                    j--;
                }
                output = output.substr(0, j+2);
            }
            else{
                output += num[i];
            }
        }
        int j = output.length()-1;
        while(del < k){
            j--;
            del++;
        }
        output = output.substr(0, j+1);

        i = 0;
        while(i < output.length() && output[i] == '0'){
            i++;
        }
        if(i == output.length()){
            return "0";
        }
        else{
            return output.substr(i);
        }
    }
};
