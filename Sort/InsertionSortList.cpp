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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL){
            return head;
        }

        ListNode *cur = head->next, *tail = head;
        ListNode *prev, *temp;
        while(cur != NULL){
            prev = NULL;
            temp = head;
            while(temp != cur && temp->val <= cur->val){
                prev = temp;
                temp = temp->next;
            }

            if(temp != cur){
                if(prev == NULL){
                    tail->next = cur->next;
                    cur->next = head;
                    head = cur;
                }
                else{
                    tail->next = cur->next;
                    prev->next = cur;
                    cur->next = temp;
                }
            }
            else{
                tail = cur;
            }
            cur = tail->next;
        }
        return head;
    }
};
