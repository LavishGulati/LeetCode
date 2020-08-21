/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
#define pb push_back
#define pf push_front


class NestedIterator {
public:
    deque<NestedInteger> dq;

    NestedIterator(vector<NestedInteger> &nestedList) {
        int n = nestedList.size();
        for(int i = 0; i < n; i++){
            dq.pb(nestedList[i]);
        }
    }

    int next() {
        while(!dq.empty() && !dq.front().isInteger()){
            vector<NestedInteger> v = dq.front().getList();
            dq.pop_front();
            int n = v.size();
            for(int i = n-1; i >= 0; i--){
                dq.pf(v[i]);
            }
        }

        int ans = dq.front().getInteger();
        dq.pop_front();
        return ans;
    }

    bool hasNext() {
        while(!dq.empty() && !dq.front().isInteger()){
            vector<NestedInteger> v = dq.front().getList();
            dq.pop_front();
            int n = v.size();
            for(int i = n-1; i >= 0; i--){
                dq.pf(v[i]);
            }
        }

        return (dq.size() > 0);
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
