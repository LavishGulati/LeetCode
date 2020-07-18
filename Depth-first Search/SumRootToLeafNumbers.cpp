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
class Solution {
public:
    int sum;

    void sumNumbers(TreeNode *root, int s){
        s = 10*s+root->val;

        if(root->left == NULL && root->right == NULL){
            sum += s;
            return;
        }

        if(root->left != NULL){
            sumNumbers(root->left, s);
        }
        if(root->right != NULL){
            sumNumbers(root->right, s);
        }
    }

    int sumNumbers(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        sum = 0;
        sumNumbers(root, 0);
        return sum;
    }
};
