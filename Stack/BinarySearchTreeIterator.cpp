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
class BSTIterator {
public:
    stack<TreeNode *> st;

    BSTIterator(TreeNode* root) {
        TreeNode *head = root;
        while(head != NULL){
            st.push(head);
            head = head->left;
        }
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *head = st.top();
        st.pop();
        TreeNode *temp = head->right;
        while(temp != NULL){
            st.push(temp);
            temp = temp->left;
        }
        return head->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (!st.empty());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
