class Solution {
public:
    bool possible(string s, string d){
        int i = 0, j = 0;
        while(j < d.length() && i < s.length()){
            if(s[i] == d[j]){
                i++; j++;
            }
            else{
                i++;
            }
        }

        if(j == d.length()){
            return true;
        }
        else{
            return false;
        }
    }

    string findLongestWord(string s, vector<string>& d) {
        string output = "";
        int n = d.size();
        for(int i = 0; i < n; i++){
            if(possible(s, d[i])){
                if(d[i].length() > output.length()){
                    output = d[i];
                }
                else if(d[i].length() == output.length() && d[i] < output){
                    output = d[i];
                }
            }
        }
        return output;
    }
};
