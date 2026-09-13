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

    void rightview(TreeNode* root, int l1, vector<int>&v1){
        if(root==NULL){
            return;
        }
        if(v1.size()==l1){
            v1.push_back(root->val);
        }
        rightview(root->right,l1+1,v1);
        rightview(root->left,l1+1,v1);

    }
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int>v1;
      rightview(root,0,v1);
      return v1;

    }
};
