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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }

        int size = 0;
        ListNode *temp = head;
        while(temp != NULL){
            size++;
            temp = temp->next;
        }

        if(k%size == 0){
            return head;
        }

        ListNode *prevv = NULL;
        ListNode *prev = head, *tempp = NULL;
        temp = head;
        int num = 0;
        while(num < k%size){
            tempp = temp;
            temp = temp->next;
            num++;
        }

        while(temp != NULL){
            prevv = prev;
            tempp = temp;
            prev = prev->next;
            temp = temp->next;
        }

        tempp->next = head;
        prevv->next = NULL;
        head = prev;
        return head;
    }
};
