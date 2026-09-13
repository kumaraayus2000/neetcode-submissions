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
    bool isSame(TreeNode *r1, TreeNode *r2){
        if(r1==NULL && r2==NULL){
            return true;
        }
        if(r1==NULL || r2==NULL){
            return false;
        }
        if(r1->val == r2->val){
            return isSame(r1->left,r2->left) && isSame(r1->right,r2->right);
        }else{
            return false;
        }

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL){
            return false;
        }
        if(isSame(root,subRoot)){
            return true;
        }
        return (isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));
    }
};
