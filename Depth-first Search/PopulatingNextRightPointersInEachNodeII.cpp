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
    Node *root;
    int depth;

    Node *dfs(Node *root, Node *temp, int dep){
        if(root == NULL){
            return NULL;
        }
        if(root == temp){
            depth = dep;
            return NULL;
        }

        if(depth > 0 && depth == dep){
            return root;
        }

        Node *rightAns = dfs(root->right, temp, dep+1);
        if(rightAns != NULL){
            return rightAns;
        }
        Node *leftAns = dfs(root->left, temp, dep+1);
        if(leftAns != NULL){
            return leftAns;
        }

        return NULL;
    }

    Node *connect(Node *root, Node *temp){
        if(root == NULL){
            return NULL;
        }

        if(temp != NULL){
            temp->next = root;
        }

        Node *temp2;
        if(root->left != NULL){
            if(temp != NULL && temp->right != NULL){
                temp2 = connect(root->left, temp->right);
            }
            else if(temp != NULL && temp->left != NULL){
                temp2 = connect(root->left, temp->left);
            }
            else if(temp != NULL){
                temp = dfs(this->root, root->left, 0);
                this->depth = 0;
                temp2 = connect(root->left, temp);
            }
            else{
                temp2 = connect(root->left, NULL);
            }

            connect(root->right, temp2);
        }
        else{
            if(temp != NULL && temp->right != NULL){
                connect(root->right, temp->right);
            }
            else if(temp != NULL && temp->left != NULL){
                connect(root->right, temp->left);
            }
            else if(temp != NULL){
                temp = dfs(this->root, root->right, 0);
                this->depth = 0;
                temp2 = connect(root->right, temp);
            }
            else{
                connect(root->right, NULL);
            }
        }

        return root;
    }

    Node* connect(Node* root) {
        this->root = root;
        depth = 0;
        connect(root, NULL);
        return root;
    }
};
