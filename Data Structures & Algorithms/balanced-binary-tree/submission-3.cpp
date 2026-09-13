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

class Solution {
public:
    int height(TreeNode * root){
        if(root==NULL){
            return 0;
        }
        int l1 = 1 + height(root->left);
        int r1= 1 + height(root->right);
        return max(l1,r1);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }

        int l1 = height(root->left);
        int r1= height(root->right);
        if(abs(l1-r1)>1){
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
