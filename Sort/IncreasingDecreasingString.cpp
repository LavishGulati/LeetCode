class Solution {
public:
    string sortString(string s) {
        int *freq = new int[26];
        for(int i = 0; i < 26; i++){
            freq[i] = 0;
        }
        int n = s.length();
        for(char c : s){
            freq[c-'a']++;
        }

        string output = "";
        bool forward = true;
        int id = 0;
        char c;
        while(n > 0){
            if(id == -1){
                id = 0;
                forward = true;
            }
            else if(id == 26){
                id = 25;
                forward = false;
            }

            if(forward){
                if(freq[id] > 0){
                    c = 'a'+id;
                    output += c;
                    n--; freq[id]--;
                }
                id++;
            }
            else{
                if(freq[id] > 0){
                    c = 'a'+id;
                    output += c;
                    n--; freq[id]--;
                }
                id--;
            }
        }
        return output;
    }
};
