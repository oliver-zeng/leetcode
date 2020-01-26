class Solution {
public:
    int romanToInt(string s) {
        map<char, int> roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;
        const char* str = s.data();
        int size = strlen(str);
        //bool negate = false;
        int i, result = 0;
        for (i = 0; i < size; i++) {
            if (i > 0 && roman[str[i]] > roman[str[i-1]]) {
            	result -= 2*roman[str[i-1]];
            }
            result += roman[str[i]];
        }
        return result;
    }
};
