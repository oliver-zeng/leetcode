// DFS 深度优先搜索算法（Depth-First-Search）
// 首次进入递归，要安排用相同方法处理左右孩子，以及处理自身的顺序
// 用栈来模拟，也就是首次出栈时，要安排好定下自身节点的处理顺序
// 当出栈的是已经处于正确处理顺序的节点（ordered的节点）时，对其进行处理
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        stack<pair<TreeNode*, bool>> st;
        st.push(make_pair(root, false));
        while(!st.empty()) {
            TreeNode *node = st.top().first;
            bool order = st.top().second;
            st.pop();
            if (order) {
                swap(node->left, node->right);
            } else {
                if (node->right) st.push(make_pair(node->right, false));
                if (node->left) st.push(make_pair(node->left, false));
                st.push(make_pair(node, true));
            }
        }
        return root;
    }
};