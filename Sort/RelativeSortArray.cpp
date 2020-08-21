// Solution 1 -- O(m+nlogn) time and O(m) space
#define umap unordered_map
#define all(x) x.begin(), x.end()

umap<int, int> mp;

bool compare(int a, int b){
    bool a1 = (mp.find(a) != mp.end());
    bool b1 = (mp.find(b) != mp.end());
    if(a1 && b1){
        return mp[a] < mp[b];
    }
    else if(a1 && !b1){
        return true;
    }
    else if(!a1 && b1){
        return false;
    }
    else{
        return a < b;
    }
}

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();

        mp.clear();
        for(int i = 0; i < m; i++){
            mp[arr2[i]] = i;
        }

        sort(all(arr1), compare);
        return arr1;
    }
};


// Solution 2 -- O(MAX+n+m) time and O(MAX) space
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        vector<int> count(1001, 0);
        for(int i = 0; i < n; i++){
            count[arr1[i]]++;
        }

        int id = 0;
        for(int i = 0; i < m; i++){
            while(count[arr2[i]] > 0){
                arr1[id] = arr2[i];
                id++;
                count[arr2[i]]--;
            }
        }

        for(int i = 0; i < 1001; i++){
            while(count[i] > 0){
                count[i]--;
                arr1[id] = i;
                id++;
            }
        }
        return arr1;
    }
};
