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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        if(root == NULL){
            return output;
        }

        stack<TreeNode *> st;
        st.push(root);
        TreeNode *head = root->left;


        while(!st.empty()){
            if(head == NULL){
                head = st.top();
                output.pb(head->val);
                st.pop();
                if(head->right != NULL){
                    st.push(head->right);
                    head = head->right->left;
                }
                else{
                    head = NULL;
                }
            }
            else{
                st.push(head);
                head = head->left;
            }
        }
        return output;
    }
};
