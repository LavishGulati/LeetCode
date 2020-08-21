class Solution {
public:
    void buildTree(int *tree, vector<int> &target, int si, int ei, int id){
        if(si == ei){
            tree[id] = si;
            return;
        }

        int mid = (si+ei)/2;
        buildTree(tree, target, si, mid, 2*id);
        buildTree(tree, target, mid+1, ei, 2*id+1);
        tree[id] = (target[tree[2*id]] <= target[tree[2*id+1]] ? tree[2*id] : tree[2*id+1]);
    }

    int query(int *tree, vector<int> &target, int si, int ei, int start, int end, int id){
        if(si > end || ei < start){
            return -1;
        }
        else if(si >= start && ei <= end){
            return tree[id];
        }

        int mid = (si+ei)/2;
        int a = query(tree, target, si, mid, start, end, 2*id);
        int b = query(tree, target, mid+1, ei, start, end, 2*id+1);
        if(a == -1){
            return b;
        }
        else if(b == -1){
            return a;
        }
        else{
            return (target[a] <= target[b] ? a : b);
        }
    }

    int minNumberOperations(int *tree, vector<int> &target, int si, int ei, int x, int n){
        if(si > ei){
            return 0;
        }
        else if(si == ei){
            return target[si]-x;
        }

        int id = query(tree, target, 0, n-1, si, ei, 1);
        int ans = target[id]-x;

        ans += minNumberOperations(tree, target, si, id-1, target[id], n);
        ans += minNumberOperations(tree, target, id+1, ei, target[id], n);
        return ans;
    }

    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int *tree = new int[4*n];
        buildTree(tree, target, 0, n-1, 1);

        return minNumberOperations(tree, target, 0, n-1, 0, n);
    }
};
