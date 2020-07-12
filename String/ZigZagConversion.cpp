class Solution {
public:
    string convert(string s, int r) {
        if(r == 1){
            return s;
        }

        int n = s.length();
        string output = "";
        for(int i = 0; i < r; i++){
            int j = i;
            if(i == 0 || i == r-1){
                while(j < n){
                    output += s[j];
                    j += 2*r-2;
                }
            }
            else{
                while(j < n){
                    output += s[j];
                    if(j+2*r-(i+1)*2 < n){
                        output += s[j+2*r-(i+1)*2];
                    }
                    j += 2*r-2;
                }
            }
        }
        return output;
    }
};
