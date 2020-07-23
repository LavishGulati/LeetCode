bool compare(string &a, string &b){
    return (a+b) < (b+a);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        string *mod = new string[n];
        for(int i = 0; i < n; i++){
            mod[i] = to_string(nums[i]);
        }

        sort(mod, mod+n, compare);
        string output = "";
        for(int i = n-1; i >= 0; i--){
            output += mod[i];
        }
        int i = 0;
        while(i < output.size() && output[i] == '0'){
            i++;
        }

        if(i == output.size()){
            output = "0";
        }
        else{
            output = output.substr(i);
        }
        return output;
    }
};
