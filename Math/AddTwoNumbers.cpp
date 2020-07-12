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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head1 = l1, *head2 = l2;
        int carry = 0;
        ListNode *root = NULL, *head;
        while(head1 != NULL || head2 != NULL){
            int x = carry;
            if(head1 != NULL){
                x += head1->val;
                head1 = head1->next;
            }
            if(head2 != NULL){
                x += head2->val;
                head2 = head2->next;
            }
            ListNode *newNode = new ListNode(x%10);
            carry = x/10;

            if(root == NULL){
                root = newNode;
                head = root;
            }
            else{
                head->next = newNode;
                head = head->next;
            }
        }
        if(carry > 0){
            ListNode *newNode = new ListNode(carry);
            head->next = newNode;
            head = head->next;
        }
        return root;
    }
};
