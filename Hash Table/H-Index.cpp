#define all(x) x.begin(), x.end()

class Solution {
public:
    int binary_search(vector<int> &citations, int x, int n){
        int si = 0; int ei = n-1;
        int mid, ans = n;
        while(si <= ei){
            mid = (si+ei)/2;
            if(citations[mid] >= x){
                ans = mid;
                ei = mid-1;
            }
            else{
                si = mid+1;
            }
        }
        return ans;
    }

    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(all(citations));

        int si = 1, ei = n;
        int mid, ans = 0;
        while(si <= ei){
            mid = (si+ei)/2;
            int id = binary_search(citations, mid, n);
            if(n-id >= mid){
                ans = mid;
                si = mid+1;
            }
            else{
                ei = mid-1;
            }
        }
        return ans;
    }
};
