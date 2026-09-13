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
    int height(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        int l1 = 1+ height(root->left);
        int r1= 1+ height(root->right);
        return max(l1,r1);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int l1 = height(root->left);
        int r1 = height(root->right);

        int dia1= diameterOfBinaryTree(root->left);
        int dia2 = diameterOfBinaryTree(root->right);

        return max(max(dia1,dia2),l1+r1);
    }
};
