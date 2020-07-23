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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head;
        ListNode *prev = head;
        ListNode *par = NULL;
        for(int i = 0; i < n; i++){
            temp = temp->next;
        }

        while(temp != NULL){
            par = prev;
            prev = prev->next;
            temp = temp->next;
        }

        if(par == NULL){
            return head->next;
        }
        else{
            par->next = prev->next;
            return head;
        }
    }
};
