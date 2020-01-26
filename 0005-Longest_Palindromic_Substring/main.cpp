class Solution {
public:
    string longestPalindrome(string s) {
        // make sure the inedex of all regions are legal
        // [0,i) i (i, 2i]
        // i < size
        // 2i > size ? size : 2i => i > size>>1 ? size : 2i
        char* str = s.data();
        int left, right, len;
        unsigned int size = strlen(str);
        unsigned int max_len = 1;
        int max_index = 0;
        char* result;
        for ( int i = 0; i < size; i++ ) {
            // make sure the index after loop break
            left = i-1;
            right = i+1;
            while (left>=0 && str[left] == str[i])
                left--;
            //left = left < 0 ? 0 : left+1;
            
            while (right<size && str[right] == str[i])
                right++;
            //right = right > size - 1 ? size - 1 : right - 1;
            
            //len = right - left + 1;
            //if (len > max_len) {
              //  max_len = len;
                //max_index = left;
            //}
            
            while (left >= 0 && right <= size - 1) {
                if (str[left] != str[right]) {
                    len = (right - 1) - (left + 1) + 1;
                    //if (len > max_len) {
                      //  max_len = len;
                        //max_index = left + 1;
                    //}
                    break;
                } else {
                    left--;
                    right++;
                }
            }
            len = (right-left-1);
            if (len > max_len) {
                max_len = len;
                max_index=left+1;
            }
        }
        result = new char[max_len+1];
        memcpy(result, str+max_index, max_len);
        result[max_len] = '\0';
        return result;
    }
};
