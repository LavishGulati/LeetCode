class Solution {
public:
    int pos(int *arr){
        int ans = 0;
        for(int i = 0; i < 26; i++){
            if(arr[i] > 0){
                ans++;
            }
        }
        return ans;
    }

    int numSplits(string s) {
        int n = s.length();
        int *left = new int[26];
        int *right = new int[26];
        for(int i = 0; i < 26; i++){
            left[i] = right[i] = 0;
        }

        for(int i = 0; i < n; i++){
            right[s[i]-'a']++;
        }

        int ans = 0;
        for(int i = 0; i < n-1; i++){
            left[s[i]-'a']++;
            right[s[i]-'a']--;
            if(pos(left) == pos(right)){
                ans++;
            }
        }
        return ans;
    }
};
