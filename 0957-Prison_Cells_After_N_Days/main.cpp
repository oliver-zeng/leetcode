class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        int sz = cells.size();
        // 每一步是由旧的cell得到新的cell，所以必须有next存储新的，不能覆盖
        // next初始化为0，就不用考虑之后next[0] & next[sz-1]永为0的问题了
        // key也只记录(0, sz-1)区间即可，后面初始化res也是0，根据key填(0, sz-1)区间即可
        vector<int> next(sz, 0);
        unordered_set<string> st;
        unordered_map<int, string> dict;
        int count = 0;
        int times = N;
        while (times--) {
            string key = "#";
            for (int i = 1; i < sz - 1; i++) {
                next[i] = cells[i-1] == cells[i+1];
                key += to_string(next[i]) + "#";
            }
            cells = next;
        	if (st.count(key)) break;
            count++; // count++在break后面，这样count就是不重复的个数
            //cout << count << " " << key << endl;
            st.insert(key);
            dict[count-1] = key; // 由于count是从1开始，为了对应后面的求模运算必须变为从0开始
		}
        vector<int> res(sz, 0);
        string str = dict[(N-1) % count];
        //cout << str << endl;
        int left = 1, right = 1;
        count = 0;
        while (right < str.size()) {
            while (str[right] != '#') right++;
            count++;
            res[count] = str[left] == '1';
            right++;
            left = right;
        }
		return res;
	}
};