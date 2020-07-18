/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node *connect(Node *root, Node *temp){
        if(root == NULL){
            return NULL;
        }

        if(temp != NULL){
            temp->next = root;
        }

        Node *temp2;
        if(temp != NULL){
            temp2 = connect(root->left, temp->right);
        }
        else{
            temp2 = connect(root->left, NULL);
        }

        connect(root->right, temp2);

        return root;
    }

    Node* connect(Node* root) {
        connect(root, NULL);
        return root;
    }
};
