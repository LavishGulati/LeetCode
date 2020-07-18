/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }

        map<Node *, Node *> mp;
        Node *temp = head;
        Node *root = NULL;
        Node *tail = NULL, *newNode;
        while(temp != NULL){
            if(mp.find(temp) == mp.end()){
                newNode = new Node(temp->val);
                mp[temp] = newNode;
            }
            else{
                newNode = mp[temp];
            }

            if(tail == NULL){
                root = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = tail->next;
            }

            if(temp->random != NULL){
                if(mp.find(temp->random) == mp.end()){
                    newNode = new Node(temp->random->val);
                    mp[temp->random] = newNode;
                    tail->random = newNode;
                }
                else{
                    tail->random = mp[temp->random];
                }
            }

            temp = temp->next;
        }
        return root;
    }
};
