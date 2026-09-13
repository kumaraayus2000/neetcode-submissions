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
    bool bst(TreeNode* root, int l1,int l2){
       if(root==NULL){
        return true;
       }
        if(root->val < l1 || root->val > l2){
            return false;
        }
        return bst(root->left,l1,root->val-1) && bst(root->right,root->val+1,l2);

    }
    bool isValidBST(TreeNode* root) {
       if(root==NULL){
        return true;
       }
        int l1 =INT_MIN;
        int l2 = INT_MAX;

        return bst(root,l1,l2);


    }
};
