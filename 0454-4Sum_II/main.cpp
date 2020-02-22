class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        // 之前是一个数组里选4个数，现在是在4个等长数组里选4个数
        // 并且这题要的是(i, j, k, l)的个数，也就是说只要下标不同就算不同解
        // 即如果取了一个数组里有n个的数，那算n次结果
        // 所以也就不用排序去重，避免踩踏同一个值了
        int sz = A.size();
        int res = 0;
        unordered_map<int, int> record;
        for (int i = 0; i < sz; i++)
            for (int j = 0; j < sz; j++)
                record[A[i] + B[j]]++;
        for (int i = 0; i < sz; i++)
            for (int j = 0; j < sz; j++)
                if (record.find(0 - C[i] - D[j]) != record.end())
                    res += record[0 - C[i] - D[j]];
        return res;
    }
};
