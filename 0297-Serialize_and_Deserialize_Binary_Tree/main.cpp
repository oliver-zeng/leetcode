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
        // 子串题要特别注意substr里的第一个参数有效性的判定
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
            // 注意这里不能是begin = i+1，否则i就不是从begin开始，变成begin-1了
            int begin = ++i;
            // 子串题要特别注意substr里的第一个参数有效性的判定
            if (begin >= data.size()) break;
            while (i < data.size() && data[i] != ',') i++;
            tmp = data.substr(begin, i-begin);
            if (tmp != "null") {
                node->left = new TreeNode(stoi(tmp, NULL, 10));
                qe.push(node->left);
            }
            // 放在后面，是为了防止最后一个不以','结尾的节点没有插进去就跳出了
            if (i >= data.size()) break;

            // 注意这里不能是begin = i+1，否则i就不是从begin开始，变成begin-1了
            begin = ++i;
            // 子串题要特别注意substr里的第一个参数有效性的判定
            if (begin >= data.size()) break;
            while (i < data.size() && data[i] != ',') i++;
            tmp = data.substr(begin, i-begin);
            if (tmp != "null") {
                node->right = new TreeNode(stoi(tmp, NULL, 10));
                qe.push(node->right);
            }
            // 放在后面，是为了防止最后一个不以','结尾的节点没有插进去就跳出了
            if (i >= data.size()) break;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));