class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s)
            freq[c]++;
        priority_queue<pair<int, char>> pq;
        for (auto elm : freq)
            pq.push(make_pair(elm.second, elm.first));
        string res = "";
        while (!pq.empty()) {
            auto elm = pq.top();
            pq.pop();
            for (int i = 0; i < elm.first; i++)
                res += elm.second;
        }
        return res;
    }
};