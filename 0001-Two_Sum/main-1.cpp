class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unsigned int size = nums.size();
        for (int i =0; i < size; i++){
            //for ( int j = 0; j < size; j++) {
            for ( int j = i+1;j < size; j++) {    
                //if ( i != j && nums[i] + nums[j] == target){
                if ( nums[j] == target - nums[i]){    
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};
