// merge sort (bottom to up)
class Solution {
private:
    // 将[left, right]中两有序序列[left, mid]和[mid+1, right]合成一个
    void merge(vector<int> &arr, int left, int mid, int right) {
        int tmp[right - left + 1];
        int i = left, j = mid + 1, k = 0;
        while (i <= mid && j <= right) {
            if (arr[i] > arr[j])
                tmp[k++] = arr[j++];
            else
                tmp[k++] = arr[i++];
        }
        while (i <= mid)
            tmp[k++] = arr[i++];
        while (j <= right)
            tmp[k++] = arr[j++];
        for (int i = 0; i < right - left + 1; i++)
            arr[i + left] = tmp[i];
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        int sz = nums.size();
        // 当 len = sz 时就没有两段可以merge了，所以是len < sz
        for (int len = 1; len < sz; len *= 2)
            // 对 [left, mid] 和 [mid + 1, right] 进行归并
            // 即 [i, i + len - 1] 和 [i + len, min(i + len + len - 1, sz - 1)]
            // 要确保 i + len 位置上有数存在，即后一段长度不为0，这样才有必要进行merge
            // 又因为后面剩余长度不一定够len，所以要确保 i + len + len - 1 <= sz - 1
            for (int i = 0; i + len < sz; i += len + len)
                merge(nums, i, i + len - 1, min(i + len + len - 1, sz - 1));
        return nums;
    }
};