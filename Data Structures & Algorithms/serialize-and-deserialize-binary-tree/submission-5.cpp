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

class Codec {
public:

    // Encodes a tree to a single string.
    void serializeHelper(TreeNode* root, string &result){
        if(root==NULL){
            result+="#,";
            return;
        }
        result+= to_string(root->val) + ",";
        serializeHelper(root->left,result);
        serializeHelper(root->right,result);
    }
    string serialize(TreeNode* root) {
        string result;
        serializeHelper(root,result);
        if (!result.empty()) result.pop_back();  // remove trailing comma

        return result;
    }

    TreeNode *deserializehelper(queue<string> &nodes){
        if(nodes.empty()){
            return NULL;
        }
        string val = nodes.front();
        nodes.pop();
        if(val=="#"){
            return NULL;
        }
        TreeNode *root = new TreeNode(stoi(val));
        root->left= deserializehelper(nodes);
        root->right = deserializehelper(nodes);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string item;
        queue<string>nodes;
        while(getline(ss,item,',')){
            nodes.push(item);
        }
        return deserializehelper(nodes);
    }
};
