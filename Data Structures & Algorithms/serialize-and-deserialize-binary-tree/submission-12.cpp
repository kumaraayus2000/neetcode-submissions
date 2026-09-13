class Codec {
public:
    void serializeHelper(TreeNode* root, string &result){
        if (!root) {
            result += "#,";
            return;
        }
        result += to_string(root->val) + ",";
        serializeHelper(root->left, result);
        serializeHelper(root->right, result);
    }

    string serialize(TreeNode* root) {
        string result;
        serializeHelper(root, result);
        if (!result.empty()) result.pop_back();  // remove trailing comma
        return result;
    }

    TreeNode* deserializeHelper(queue<string>& nodes) {
        if (nodes.empty()) return nullptr;
        string val = nodes.front(); nodes.pop();
        if (val == "#") return nullptr;

        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserializeHelper(nodes);
        root->right = deserializeHelper(nodes);
        return root;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        stringstream ss(data);
        string item;
        queue<string> nodes;
        while (getline(ss, item, ',')) {
            nodes.push(item);
        }
        return deserializeHelper(nodes);
    }
};
