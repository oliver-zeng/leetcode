class RandomizedSet {
    unordered_map<int, int> map;
    vector<int> vec;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (map.find(val) != map.end())
            return false;
        vec.push_back(val);
        map[val] = vec.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    // 删除任意索引元素需要线性时间，这里的解决方案是总是删除最后一个元素。
    // 将要删除元素和最后一个元素交换。将最后一个元素删除。
    bool remove(int val) {
        if (map.find(val) == map.end())
            return false;
        int index = map[val];
        // 先把index换了，再swap，否则swap再换就又回去了
        map[vec[vec.size()-1]] = index;
        swap(vec[index], vec[vec.size()-1]);
        //map[vec[vec.size()-1]] = index;
        vec.pop_back();
        map.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vec[rand() % vec.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */