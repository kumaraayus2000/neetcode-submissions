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
 
    int preindex=0;
     TreeNode* tree1(vector<int>& preorder, vector<int>& inorder, int l,int h
     ,unordered_map<int,int>mp){
        
        if(l>h){
            return NULL;
        }
        TreeNode *root1 = new TreeNode(preorder[preindex]);
        int mid = mp[preorder[preindex]];
        preindex++;

        root1->left = tree1(preorder,inorder,l,mid-1,mp);
        root1->right = tree1(preorder,inorder,mid+1,h,mp);
        return root1;
        }
        
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }

       return tree1(preorder,inorder,0,inorder.size()-1,mp);
    }
};
