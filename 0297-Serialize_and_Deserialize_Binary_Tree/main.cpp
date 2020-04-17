/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "null";
        string res;
        queue<TreeNode*> qe;
        qe.push(root);
        while (!qe.empty()) {
            TreeNode *node = qe.front();
            qe.pop();
            if (!node) {
                res += "null,";
            } else {
                res += to_string(node->val) + ",";
                qe.push(node->left);
                qe.push(node->right);
            }
        }
        res.pop_back();
        // remove ",null"
        int sz = strlen(",null");
        while (res.size() >= sz && res.substr(res.size() - sz, sz) == ",null")
            res.erase(res.size() - sz, sz);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "")
            return NULL;
        int i = 0;
        while (i < data.size() && data[i] != ',') i++;
        string tmp = data.substr(0, i);
        if (tmp == "null")
            return NULL;
        TreeNode* root = new TreeNode(stoi(tmp, NULL, 10));
        queue<TreeNode*> qe;
        qe.push(root);
        while (!qe.empty()) {
            TreeNode* node = qe.front();
            qe.pop();
            int begin = ++i;
            if (begin >= data.size()) break;
            while (i < data.size() && data[i] != ',') i++;
            tmp = data.substr(begin, i-begin);
            if (tmp != "null") {
                node->left = new TreeNode(stoi(tmp, NULL, 10));
                qe.push(node->left);
            }
            if (i >= data.size()) break;
            
            begin = ++i;
            if (begin >= data.size()) break;
            while (i < data.size() && data[i] != ',') i++;
            tmp = data.substr(begin, i-begin);
            if (tmp != "null") {
                node->right = new TreeNode(stoi(tmp, NULL, 10));
                qe.push(node->right);
            }
            if (i >= data.size()) break;
            
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));