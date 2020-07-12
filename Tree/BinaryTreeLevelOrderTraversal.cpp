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
#define pb push_back

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector< vector<int> > output;
        vector<int> temp;
        vector<TreeNode *> cur, next;
        if(root == NULL){
            return output;
        }

        cur.pb(root);
        while(1){
            temp.clear();
            next.clear();
            for(TreeNode *u : cur){
                temp.pb(u->val);
                if(u->left != NULL){
                    next.pb(u->left);
                }
                if(u->right != NULL){
                    next.pb(u->right);
                }
            }

            cur = next;
            output.pb(temp);
            if(cur.size() == 0){
                break;
            }
        }

        return output;
    }
};
