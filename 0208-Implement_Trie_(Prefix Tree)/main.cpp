class Trie {
private:
    // trie node 是多叉树节点，这里node是用vector来存放
    // 好处是：cpp没有gc，用vector就可避免每次new一个node到后面还要手动释放
    // 这样 trie node 的指针域next就是一个查找表
    // 指针域里每一个key指向一个独立的新节点，依次将前缀中的一个字符记录到每个节点的key里
    // 将查找表用map实现
    // 好处是：map不会造成每个节点中的指针域有大量为空的浪费
    // 最后在每个节点里设一个flag，用来记录是否有前缀串在此节点结束
    // 这样记录了application，搜索单词app就不会被查到
    struct Node{
        map<char, int> next;
        bool end = false;
    };
    vector<Node> trie;
public:
    /** Initialize your data structure here. */
    Trie() {
        trie.clear();
        trie.push_back(Node());
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        int nextID = 0;
        for (const char c : word) {
            // 这里用lookup拷贝就会错，to-do map的赋值运算符失效
            // map<char, int> lookup = trie[nextID].next;
            // 如果查找表中还没有就新增一个节点
            if (trie[nextID].next.find(c) == trie[nextID].next.end()) {
                trie[nextID].next[c] = trie.size();
                trie.push_back(Node());
            }
            nextID = trie[nextID].next[c];
        }
        trie[nextID].end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        int nextID = 0;
        for (const char c : word) {
            map<char, int> &lookup = trie[nextID].next;
            if (lookup.find(c) == lookup.end())
                return false;
            nextID = lookup[c];
        }
        // search 必须严格匹配，查到的要是正好结尾的单词
        return trie[nextID].end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int nextID = 0;
        for (const char c : prefix) {
            map<char, int> &lookup = trie[nextID].next;
            if (lookup.find(c) == lookup.end())
                return false;
            nextID = lookup[c];
        }
        // startsWith 只要有这个前缀就行，并不会要求这个前缀是个单词
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