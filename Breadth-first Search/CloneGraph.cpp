/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
typedef pair<Node *, Node *> pnn;
#define mp make_pair
#define f first
#define s second
#define umap unordered_map
#define pb push_back


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }

        queue<pnn> q;
        Node *null = NULL;
        q.push(mp(null, node));
        umap<int, Node *> temp;

        Node *root = new Node(node->val);
        temp[node->val] = root;

        while(!q.empty()){
            pnn u = q.front();
            q.pop();
            Node *head = temp[u.s->val];

            for(Node *v : u.s->neighbors){
                if(temp.find(v->val) == temp.end()){
                    Node *newNode = new Node(v->val);
                    temp[v->val] = newNode;
                    q.push(mp(u.s, v));
                }
                head->neighbors.pb(temp[v->val]);
            }
        }
        return root;
    }
};
