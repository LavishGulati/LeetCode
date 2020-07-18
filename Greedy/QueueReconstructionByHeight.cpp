#define all(x) x.begin(), x.end()

bool compare(vector<int> &a, vector<int> &b){
    if(a[0] != b[0]){
        return a[0] < b[0];
    }
    else{
        return a[1] > b[1];
    }
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(all(people), compare);

        vector<vector<int>> output(n);
        vector<int> help;
        for(int i = 0; i < n; i++){
            int num = 0, j = 0;
            while(j < n && output[j].size() > 0){
                j++;
            }

            while(num < people[i][1]){
                num++;
                j++;
                while(j < n & output[j].size() > 0){
                    j++;
                }
            }

            output[j] = people[i];
        }
        return output;
    }
};
