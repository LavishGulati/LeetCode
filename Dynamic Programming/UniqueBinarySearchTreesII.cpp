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
    vector<TreeNode *> generateTrees(int si, int ei){
        vector<TreeNode *> output;
        
        if(si > ei){
            return output;
        }
        else if(si == ei){
            TreeNode *newNode = new TreeNode(si);
            output.pb(newNode);
            return output;
        }
        
        for(int i = si; i <= ei; i++){
            vector<TreeNode *> leftChild = generateTrees(si, i-1);
            vector<TreeNode *> rightChild = generateTrees(i+1, ei);
            if(leftChild.size() == 0 && rightChild.size() == 0){
                TreeNode *newNode = new TreeNode(i);
                newNode->left = NULL;
                newNode->right = NULL;
                output.pb(newNode);
            }
            else if(leftChild.size() == 0){
                for(int k = 0; k < rightChild.size(); k++){
                    TreeNode *newNode = new TreeNode(i);
                    newNode->left = NULL;
                    newNode->right = rightChild[k];
                    output.pb(newNode);
                }
            }
            else if(rightChild.size() == 0){
                for(int j = 0; j < leftChild.size(); j++){
                    TreeNode *newNode = new TreeNode(i);
                    newNode->left = leftChild[j];
                    newNode->right = NULL;
                    output.pb(newNode);
                }
            }
            else{
                for(int j = 0; j < leftChild.size(); j++){
                    for(int k = 0; k < rightChild.size(); k++){
                        TreeNode *newNode = new TreeNode(i);
                        newNode->left = leftChild[j];
                        newNode->right = rightChild[k];
                        output.pb(newNode);
                    }
                }
            }
        }
        return output;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode *> output;
        for(int i = 1; i <= n; i++){
            vector<TreeNode *> leftChild = generateTrees(1, i-1);
            vector<TreeNode *> rightChild = generateTrees(i+1, n);
            if(leftChild.size() == 0 && rightChild.size() == 0){
                TreeNode *newNode = new TreeNode(i);
                newNode->left = NULL;
                newNode->right = NULL;
                output.pb(newNode);
            }
            else if(leftChild.size() == 0){
                for(int k = 0; k < rightChild.size(); k++){
                    TreeNode *newNode = new TreeNode(i);
                    newNode->left = NULL;
                    newNode->right = rightChild[k];
                    output.pb(newNode);
                }
            }
            else if(rightChild.size() == 0){
                for(int j = 0; j < leftChild.size(); j++){
                    TreeNode *newNode = new TreeNode(i);
                    newNode->left = leftChild[j];
                    newNode->right = NULL;
                    output.pb(newNode);
                }
            }
            else{
                for(int j = 0; j < leftChild.size(); j++){
                    for(int k = 0; k < rightChild.size(); k++){
                        TreeNode *newNode = new TreeNode(i);
                        newNode->left = leftChild[j];
                        newNode->right = rightChild[k];
                        output.pb(newNode);
                    }
                }
            }
        }
        return output;
    }
};