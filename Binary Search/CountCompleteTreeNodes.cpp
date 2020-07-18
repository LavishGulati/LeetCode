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
#define all(x) x.begin(), x.end()
#define pb push_back

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        TreeNode *si = root;
        int h1 = 0;
        while(si->left != NULL){
            si = si->left;
            h1++;
        }

        TreeNode *ei = root;
        int h2 = 0;
        while(ei->right != NULL){
            ei = ei->right;
            h2++;
        }

        if(h1 == h2){
            return pow(2, h1+1)-1;
        }

        int s = pow(2, h2+1);
        int e = pow(2, h1+1)-1, ans, mid;
        bool find;
        vector<bool> moveLeft;
        while(s <= e){
            moveLeft.clear();
            mid = (s+e)/2;
            while(mid > 1){
                if(mid%2){
                    moveLeft.pb(false);
                }
                else{
                    moveLeft.pb(true);
                }
                mid /= 2;
            }
            find = true;
            reverse(all(moveLeft));
            TreeNode *head = root;
            for(int i = 0; i < moveLeft.size(); i++){\
                if(moveLeft[i]){
                    head = head->left;
                }
                else{
                    head = head->right;
                }
                if(head == NULL){
                    find = false;
                    break;
                }
            }

            if(find){
                ans = (s+e)/2;
                s = (s+e)/2 + 1;
            }
            else{
                e = (s+e)/2 - 1;
            }
        }
        return ans;
    }
};
