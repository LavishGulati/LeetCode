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
    vector<vector<int>> output;

    void pathSum(TreeNode *root, int s, vector<int> &temp, int sum){
        temp.pb(root->val);
        s += root->val;

        if(root->left == NULL && root->right == NULL){
            if(s == sum){
                output.pb(temp);
            }
        }
        else{
            if(root->left != NULL){
                pathSum(root->left, s, temp, sum);
            }
            if(root->right != NULL){
                pathSum(root->right, s, temp, sum);
            }
        }
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        output.clear();
        if(root != NULL){
            vector<int> temp;
            pathSum(root, 0, temp, sum);
        }
        return output;
    }
};
