typedef long long ll;

class Solution {
public:
    bool overflow(int a, int b){
        if(a < 0 && b > 0 && ll(b)-a > INT_MAX){
            return true;
        }
        else if(a > 0 && b < 0 && ll(a)-b > INT_MAX){
            return true;
        }
        return false;
    }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t < 0 || k < 0){
            return false;
        }

        int n = nums.size();
        set<int> st;
        for(int i = 0; i < min(n, k+1); i++){
            if(st.find(nums[i]) != st.end()){
                return true;
            }

            st.insert(nums[i]);
            auto it = st.find(nums[i]);
            if(it != st.begin()){
                auto prev = it;
                prev--;
                if(!overflow(*prev, *it) && abs(*prev-*it) <= t){
                    return true;
                }
            }
            auto next = it;
            next++;
            if(next != st.end() && !overflow(*next, *it) && (abs(*next-*it) <= t)){
                return true;
            }
        }

        for(int i = 0; i < n-k-1; i++){
            st.erase(nums[i]);
            if(st.find(nums[i+k+1]) != st.end()){
                cout << i+k+1 << endl;
                return true;
            }
            st.insert(nums[i+k+1]);
            auto it = st.find(nums[i+k+1]);
            if(it != st.begin()){
                auto prev = it;
                prev--;
                if(!overflow(*prev, *it) && abs(*prev-*it) <= t){
                    return true;
                }
            }
            auto next = it;
            next++;
            if(next != st.end() && !overflow(*next, *it) && abs(*next-*it) <= t){
                return true;
            }
        }
        return false;
    }
};
