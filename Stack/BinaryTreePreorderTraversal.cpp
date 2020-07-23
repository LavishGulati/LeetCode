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
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode *head = root;
        stack<TreeNode *> st;
        vector<int> output;
        while(head != NULL){
            output.pb(head->val);
            st.push(head);
            head = head->left;

            while(head == NULL && !st.empty() && st.top()->right == NULL){
                st.pop();
            }

            if(head == NULL && !st.empty()){
                head = st.top()->right;
                st.pop();
            }
        }
        return output;
    }
};
