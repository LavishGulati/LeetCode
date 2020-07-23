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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> output;
        if(root == NULL){
            return output;
        }

        vector<TreeNode *> cur[2];
        cur[0].pb(root);
        while(cur[0].size() > 0){
            int n = cur[0].size();
            output.pb(cur[0][n-1]->val);
            for(TreeNode *head : cur[0]){
                if(head->left != NULL){
                    cur[1].pb(head->left);
                }
                if(head->right != NULL){
                    cur[1].pb(head->right);
                }
            }
            cur[0] = cur[1];
            cur[1].clear();
        }

        return output;
    }
};
