/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// 层序遍历有两种模板
// 第一种：
// 把每个pop出节点，下一层的节点入队
// 当出队节点的层数增加时进入新层，所以必须记录层数
// 第二种：
// 把当前队列中节点个数，全部pop处理把下一层节点入队完，再处理下一层的全部节点
// 每次处理完当前队列节点时进入新层，不必记录层数，只需要记录是否访问过即可
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        // 在bfs队列中节点是按照层序，由小到大存放的
        // 在处理过程中实际上也是按层处理的，每次pop出一层的节点后，插入的是下一层的节点
        // 队列中只会同时存在有一层或两层的节点
        // 所以可以在每次队列只有同一层节点时，先获取当前队列元素数
        // 然后处理队列中元素数次的节点，等处理完队列中就只有下一层的全部节点了
        // 另外，尽管树中遍历不会重复，但图中需要解决重复问题，所以要标记出已访问过的节点
        // 知道节点index用vector来标记，或直接用unordered_set来标记都是可以的
        if (!root) return 0;
        queue<TreeNode*> qe;
        qe.push(root);
        int res = 0;
        while (!qe.empty()) {
            int sz = qe.size();
            res = 0;
            while (sz--) {
				TreeNode *node = qe.front();
                qe.pop();
                res += node->val;
                if (node->left) qe.push(node->left);
                if (node->right) qe.push(node->right);
            }
        }
        return res;
    }
};