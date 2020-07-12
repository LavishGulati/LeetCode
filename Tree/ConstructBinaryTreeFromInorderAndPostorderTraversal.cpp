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
    TreeNode *buildTree(vector<int> &inorder, int ii, int ij, vector<int> &postorder, int pi, int pj){
        if(pi > pj){
            return NULL;
        }
        else if(pi == pj){
            TreeNode *root = new TreeNode(postorder[pj]);
            return root;
        }

        TreeNode *root = new TreeNode(postorder[pj]);
        int id = ii;
        while(id <= ij && inorder[id] != postorder[pj]){
            id++;
        }

        TreeNode *left = buildTree(inorder, ii, id-1, postorder, pi, pi+id-ii-1);
        TreeNode *right = buildTree(inorder, id+1, ij, postorder, pi+id-ii, pj-1);
        root->left = left;
        root->right = right;
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode *root = buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
        return root;
    }
};
