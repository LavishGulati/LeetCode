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
#define pb push_back

class Solution {
public:
    int ans;

    vector<int> countPairsHelper(TreeNode *root, int dist){
        vector<int> output;
        if(root == NULL){
            return output;
        }
        else if(root->right == NULL && root->left == NULL){
            output.pb(1);
            return output;
        }

        vector<int> a = countPairsHelper(root->left, dist);
        vector<int> b = countPairsHelper(root->right, dist);
        for(int x : a){
            for(int y : b){
                if(x+y <= dist){
                    ans++;
                }
            }
        }

        vector<int> res;

        for(int x : a){
            if(x+1 <= dist){
                res.pb(x+1);
            }
        }
        for(int y : b){
            if(y+1 <= dist){
                res.pb(y+1);
            }
        }
        return res;
    }

    int countPairs(TreeNode* root, int distance) {
        ans = 0;
        countPairsHelper(root, distance);
        return ans;
    }
};
