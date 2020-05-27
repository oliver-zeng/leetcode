// 双链表std::list对任意节点的插入&删除操作都是O(1)
// PS：单链表则不然，在指定位置的插入&删除操作，需要先通过O(n)来得到指定位置的前驱节点
// O(1)时间查找到要操作的节点，就要用到unordered_map，key对应指向list中节点的指针
// 因为在插入的时候key肯定是已知的，但删的时候只知道是尾节点，不会给出key
// 因此在list中节点除了记录value，也要记录key
// 并且节点在list中移动是要先删除，再插入，因为list封装了指针，所以插入的是新节点
// 因此除了删除操作外，在插入的时候，也同样要更新查找表
class LRUCache {
    // list不用单设struct Node {};类型，直接用pair
    // 后面unordered_map的value是指向pair的指针，正好是list<pair>::iterator
    unordered_map<int, list<pair<int, int>>::iterator> dict;
    list<pair<int, int>> ls;
    int cap = 0;
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        if (dict.count(key) == 0)
            return -1;
        pair<int, int> node = *dict[key];
        // erase 删的都是 iter，map 除了 iter 还接收 key 来删除
        ls.erase(dict[key]);
        ls.push_front(node);
        // 因为移动是通过删除后，新增实现的，所以存放相同数据的iterator将会变化
        // 所以要更新hash map中key对应的iterator节点
        dict[key] = ls.begin();
        return node.second;
    }
    
    void put(int key, int value) {
        if (dict.count(key)) {
            pair<int, int> node = *dict[key];
            ls.erase(dict[key]);
            node.second = value;
            ls.push_front(node);
            dict[key] = ls.begin();
            return;
        }
        if (dict.size() == this->cap) {
            // begin() & end() 是 iter，front() & back() 是 节点的引用
            dict.erase(ls.back().first);
            ls.pop_back();
        }
        ls.push_front(make_pair(key, value));
        dict[key] = ls.begin();
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */