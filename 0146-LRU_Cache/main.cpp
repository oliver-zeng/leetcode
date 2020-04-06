// 缓存淘汰策略
// LRU（Least Recently Used）
// 按访问的时序来淘汰，当到达capacity时，再插入新的，就把最久没有用到的删掉
// LFU（ ）
// 按访问频率来淘汰

class LRUCache {
    int cap;
    // list底层实现是双链表
    // 双链表，在任何位置插入&删除&移动都是O(1)，可用全部都是O(1)复杂度的操作来维护当中node的顺序性
    // node类型为(key, value) 当容量达到capacity删除时，需要通过最后一个节点的key找到对应hash map里的位置
    list<pair<int, int>> cache;
    // unordered_map底层实现是哈希表
    // 可以实现O(1)复杂度来查找key，但是但是由于value数据无固定顺序
    // 需要将value指向前面以O(1)复杂度维护的head->tail访问顺序由近到远双链表的node指针iterator
    unordered_map<int, list<pair<int, int>>::iterator> record;
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    // stl的指针就是迭代器，iterator的好处是：
    // it包含指针域 & 数据域，但完全隐藏了指针域 & 及对应的具体操作
    // 用stl提供的API，将it作为参数，就可以改变存储状态了
    // 最后通过*it直接返回node的数据域
    int get(int key) {
        // 不能用 auto val = record[key]; c++里没有的key也有default值
        if (record.find(key) == record.end())
            return -1;
        // 把node的data取出来
        pair<int, int> node = *record[key];
        // 用erase删除掉iter指向的节点
        cache.erase(record[key]);
        // 重新在链表头插入数据域为data的新节点
        cache.push_front(node);
        // 因为移动是通过删除后，新增实现的，所以存放相同数据的iterator将会变化
        // 所以要更新hash map中key对应的iterator节点
        record[key] = cache.begin();
        return node.second;
    }

    void put(int key, int value) {
        /* key 存在，更改 value 并换到队头 */
        if (record.find(key) != record.end()) {
            cache.erase(record[key]);
            cache.push_front(make_pair(key, value));
            record[key] = cache.begin();
            return;
        }
        // cache 已满，删除尾部的键值对腾位置
        // cache 和 map 中的数据都要删除
        if (record.size() == cap) {
            auto it = cache.back(); // 返回的是最后一个元素的引用，不是iterator
            record.erase(it.first);
            cache.pop_back();
        }
        // cache 没满，可以直接添加
        cache.push_front(make_pair(key, value));
        record[key] = cache.begin();
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */