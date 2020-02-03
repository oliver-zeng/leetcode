#include<iostream>
#include<map>
using namespace std;

class Solution {
private:
    bool g_debug = false;
public:
    string frequencySort(string s) {

        // 在map中将pair<key_t, value_t>对调使用，即second作为key，first作为value
        // pair<key_t, value_t>中的key与value都可以修改
        // 但map中存放的pair只能修改value
        // 所以先将pair存到数组，用数组的index与pair中的value当做key
        // 来修改pair中的key，待pair中key都计算完成后，再统一存入map里
        pair<int, char> freq[256];
        for (int i = 0; i < 256; i++) {
            freq[i].first = 0;
            freq[i].second = i;
        }
        for (auto elm : s)
            freq[elm].first++;


        // map中元素是按key中升序存放的
        // 所以顺序遍历就是升序，倒序遍历就是降序
        //
        // it = m.begin(); //相当于获取了平衡树最左下面（most left）结点的迭代器   
        // cout<<"min "<<it->first<<" "<<it->second<<endl;//最小的key值   
        //
        // it = m.end(); //相当于获取了平衡树最右下面（most right）结点下一个的迭代器   
        // it--;
        // cout<<"max "<<it->first<<" "<<it->second<<endl; //最大的key值   
        //
        // sort(left, right)是按升序排序，通过默认函数模板less<T>()实现
        // sort(left, right, greater<T>())是按降序排序，通过函数模板greater<T>()实现
        // 当T为pair类型时，是按照key即pair.first来排序的

        // 这里必须是multimap，不能用map
        // 因为这里key统计的是value次数，是有可能有重复key的
        multimap<int, char> res;
        string str;
        int count;
        for (auto elm : freq)
            if (elm.first != 0) {
                if (g_debug)
                    cout << "[insert] first " << elm.first << " second " << elm.second << endl;
                res.insert(elm);
            }
        for (auto it = res.rbegin(); it != res.rend(); it++) {
            if (g_debug)
                cout << "[traverse] first " << it->first << " second " << it->second << endl;
            count = it->first;
            while ((count--) > 0)
                str += it->second;
        }

        return str;
    }
};

int main() {
    cout << Solution().frequencySort("tree") << endl;
    return 0;
}
