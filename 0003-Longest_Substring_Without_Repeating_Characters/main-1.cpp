class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const char* str = s.data();
        unsigned int size = strlen(str);//s.size();
        bool no_repeat;
        int i, j, k; // output must set 0, local variable is freedom
        if (size <= 1)
            return size;
        int output = 1;
        for (i = 0; i < size; i++) {
            no_repeat = true;
            for ( j = i + 1; j < size; j++) {
                if (!no_repeat) {
                    break;
                }
                for (k = i; k < j; k++){
                    if (str[j] == str[k])
                        no_repeat = false;
                }
                if (no_repeat) {
                	output = output < (j - i+1) ? (j - i+1) : output;
                }
            } 
        }
        return output;
    }
};
