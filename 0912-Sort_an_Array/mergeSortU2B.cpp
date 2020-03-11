// merge sort (up to buttom)
class Solution {
private:
void mergeSort(vector<int> &arr, int left, int right) {
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    // 优化的一步，当两有序序列本身就是
    // 合并后仍有序的，就不用归并了
    if (arr[mid] <= arr[mid + 1])
        return;
    // 在递归里用vector替代数组
    // 频繁申请释放效率下降非常厉害
    //vector<int> aux;
    // c++里数组大小可以用变量定义了
    int aux[right - left + 1];
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        // 为保持稳定性 i = j 时要赋值i位置的
        // 因为在原序列中i的位置本身就在j的前面
        if (arr[i] > arr[j])
            //aux.push_back(arr[j++]);
            aux[k++] = arr[j++];
        else
            //aux.push_back(arr[i++]);
            aux[k++] = arr[i++];
    }
    while (i <= mid)
        //aux.push_back(arr[i++]);
        aux[k++] = arr[i++];
    while (j <= right)
        //aux.push_back(arr[j++]);
        aux[k++] = arr[j++];
    
    for (int i = 0; i < right - left + 1; i++)
    //for (int i = 0; i < aux.size(); i++)
        arr[left + i] = aux[i];
}
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};