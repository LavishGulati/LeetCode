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
    ListNode *merge(ListNode *left, ListNode *right){
        ListNode *head, *tail;
        if(left->val <= right->val){
            head = tail = left;
            left = left->next;
        }
        else{
            head = tail = right;
            right = right->next;
        }

        while(left != NULL && right != NULL){
            if(left->val <= right->val){
                tail->next = left;
                left = left->next;
            }
            else{
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }

        if(left != NULL){
            tail->next = left;
        }
        else if(right != NULL){
            tail->next = right;
        }

        return head;
    }

    ListNode *sort(ListNode *head, ListNode *tail){
        if(head == tail){
            return head;
        }

        int num = 0;
        ListNode *temp = head;
        while(temp != NULL){
            num++;
            temp = temp->next;
        }

        num /= 2;
        ListNode *prev = NULL;
        temp = head;
        while(num > 0){
            prev = temp;
            temp = temp->next;
            num--;
        }

        ListNode *left = NULL, *right;
        if(prev != NULL){
            prev->next = NULL;
            left = sort(head, prev);
        }
        right = sort(temp, tail);
        // cout << left->val << " " << right->val << endl;

        ListNode *root = merge(left, right);
        return root;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }

        ListNode *tail = head;
        while(tail->next != NULL){
            tail = tail->next;
        }

        ListNode *root = sort(head, tail);
        ListNode *temp = root;
        while(temp != NULL){
            cout << temp->val << " ";
            temp = temp->next;
        }

        return root;
    }
};
