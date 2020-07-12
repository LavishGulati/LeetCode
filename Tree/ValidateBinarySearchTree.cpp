/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
typedef pair<int, int> pii;
#define mp make_pair
#define f first
#define s second

class Solution {
public:
    bool ans;

    pii isValidBSTHelper(TreeNode *root){
        if(root == NULL){
            return mp(INT_MAX, INT_MIN);
        }

        pii x = isValidBSTHelper(root->left);
        if(!ans){
            return mp(INT_MAX, INT_MIN);
        }

        pii y = isValidBSTHelper(root->right);
        if(!ans){
            return mp(INT_MAX, INT_MIN);
        }

        if(x.f > x.s && y.f > y.s){
            return mp(root->val, root->val);
        }
        else if(x.f > x.s && root->val < y.f){
            return mp(min(root->val, y.f), max(y.s, root->val));
        }
        else if(y.f > y.s && root->val > x.s){
            return mp(min(root->val, x.f), max(x.s, root->val));
        }
        else if(x.f <= x.s && y.f <= y.s && root->val > x.s && root->val < y.f){
            return mp(min(x.f, min(y.f, root->val)), max(x.s, max(y.s, root->val)));
        }

        ans = false;
        return mp(INT_MAX, INT_MIN);
    }

    bool isValidBST(TreeNode* root) {
        ans = true;
        isValidBSTHelper(root);
        return ans;
    }
};
