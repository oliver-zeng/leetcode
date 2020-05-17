class Solution {
    // 要想在外面使用树的root节点
    // 就不能把node定义在树里做为私有
    // 感觉应该把dfs定义到Trie里，这样TrieNode跟root也可以做私有了
    struct TrieNode {
            bool end = false;
            unordered_map<char, TrieNode*> next;
        };
    class Trie {
	public:
    	TrieNode* root;    
    	// 这种定义方法，在最后需要解决树的析构
    	Trie () {
			root = new TrieNode();
        }
        void insert (string words) {
            TrieNode* node = root;
            for (int i = words.size() - 1; i >= 0; i--) {
                if (node->next.count(words[i]) == 0)
                	node->next[words[i]] = new TrieNode();
                node = node->next[words[i]];
            }
            node->end = true;
            return;
        }
    };
    void dfs (TrieNode* root, int path, int &sum) {
        if (!root) return;
        //path++; // 如果只有root是不用加的，trie只看边
		if (root->next.size() == 0) {
            sum += path + 1; // for '#'
            return;
        }
        for (auto elm : root->next) {
            //cout << elm.first << endl;
            // trie只看边，因此只需要加dfs里的path就够了
            dfs (elm.second, path+1, sum);
        }
        return;
	}
public:
    int minimumLengthEncoding(vector<string>& words) {
		Trie tree;
        for (string elm : words)
        	tree.insert(elm);
        int res = 0;
        dfs(tree.root, 0, res);
        return res;
    }
};