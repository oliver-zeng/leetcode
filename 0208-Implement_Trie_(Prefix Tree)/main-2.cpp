class Trie {
    // 标准树节点由三部分构成
    struct TrieNode {
        // 1-数据域
        // 结束符用于区分只是前缀，还是既可以做前缀，也可以做单词
        bool end = false; // 直接在定义的时候赋值，就不需要构造函数赋初值了，要不每次构造都要赋值
        
        // 2-指针域
        // 要以O(1)时间，知道下一个节点是否存在，需要查找表
        // 因此不能是不定长数组，用到哪个就插哪个
        // 用map实现，好处是：
        // 相比定长数组，map不会造成每个节点中的指针域有大量为空的浪费
        map<char, TrieNode*> next;
        
        // 3-构造
        // 全部为空可省略，直接用默认的
        TrieNode() {}
    }; // struct / class {} 要以;结束
    // 4-根节点
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    // 构造以TrieNode作为节点的树，就是构造root节点
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for (const char c : word) {
            if (node->next.count(c) == 0)
                node->next[c] = new TrieNode();
            node = node->next[c];
        }
        node->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for (const char c : word) {
            if (node->next.count(c) == 0)
                return false;
            node = node->next[c];
        }
        if (node->end)
            return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (const char c : prefix) {
            if (node->next.count(c) == 0)
                return false;
            node = node->next[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */