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
    int count(TreeNode* root, int l1){
        if(root==NULL){
            return 0;
        }
        int count1 =0;
        if(root->val >=l1){
            count1=1;
            l1= root->val;
        }
        int left1 = count(root->left,l1);
        int right1 = count(root->right,l1);
        return count1 + left1 + right1;


    }
    int goodNodes(TreeNode* root) {
        return count(root,root->val);
    }
};
