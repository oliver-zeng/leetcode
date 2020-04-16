class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
            return {};
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            for (int j = res.size()-1; j >= 0; j--) {
                // [[1,4],[1,4]]
                if (intervals[i][0] == res[j][0] && intervals[i][1] == res[j][1]) {
                    break;
                } else if (intervals[i][0] <= res[j][0]) {
                    res.pop_back();
                } else if (intervals[i][0] > res[j][1]) {
                    res.push_back(intervals[i]);
                    break;
                } else {
                    res[j] = vector<int>({res[j][0], max(intervals[i][1], res[j][1])});
                    break;
                }
            }
            // [[1,4],[1,5]]
            if (res.size() == 0)
                res.push_back({intervals[i][0], intervals[i][1]});
        }
        return res;
    }
};