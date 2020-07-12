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
    TreeNode *buildTree(vector<int> &preorder, int pi, int pj, vector<int> &inorder, int ii, int ij){
        if(pi > pj){
            return NULL;
        }
        else if(pi == pj){
            TreeNode *root = new TreeNode(preorder[pi]);
            return root;
        }

        TreeNode *root = new TreeNode(preorder[pi]);
        int id = ii;
        while(id <= ij && inorder[id] != preorder[pi]){
            id++;
        }

        TreeNode *left = buildTree(preorder, pi+1, pi+id-ii, inorder, ii, id-1);
        TreeNode *right = buildTree(preorder, pi+id-ii+1, pj, inorder, id+1, ij);
        root->left = left;
        root->right = right;
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
        return root;
    }
};
