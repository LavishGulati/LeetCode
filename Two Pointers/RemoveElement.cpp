// Solution 1 -- O(n) time and O(1) space
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), i = 0, j = 0;
        while(i < n){
            if(nums[i] != val){
                nums[j] = nums[i];
                j++;
            }
            i++;
        }
        return j;
    }
};


/*  Solution 2 -- O(n) time and O(1) space, but more efficient in case of rare
elements */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, n = nums.size();
        int sz = n;
        while(i < sz){
            if(nums[i] == val){
                swap(nums[i], nums[sz-1]);
                sz--;
            }
            else{
                i++;
            }
        }
        return sz;
    }
};
