/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head, ListNode *tail){
        if(head == NULL || tail == NULL){
            return NULL;
        }

        TreeNode *root;
        if(head == tail){
            root = new TreeNode(head->val);
            return root;
        }

        ListNode *mid = head, *prev;
        int num = 1;
        while(mid != tail){
            num++;
            mid = mid->next;
        }

        num /= 2;
        prev = NULL;
        mid = head;
        while(num > 0){
            prev = mid;
            mid = mid->next;
            num--;
        }

        root = new TreeNode(mid->val);
        TreeNode *leftChild = sortedListToBST(head, prev);
        TreeNode *rightChild;
        if(mid->next != NULL && mid->next != tail->next){
             rightChild = sortedListToBST(mid->next, tail);
        }
        else{
            rightChild = NULL;
        }
        root->left = leftChild;
        root->right = rightChild;
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL){
            return NULL;
        }

        ListNode *tail = head;
        while(tail->next != NULL){
            tail = tail->next;
        }
        TreeNode *root = sortedListToBST(head, tail);
        return root;
    }
};
