class Solution {
private:
    vector<string> split(const string& s){

        vector<string> res;
        int start = 0;
        for(int i = start + 1 ; i <= s.size() ; )
            if(i == s.size() || s[i] == ' '){
                res.push_back(s.substr(start, i - start));
                start = i + 1;
                i = start + 1;
            }
            else
                i ++;
        return res;
    }

public:
    bool wordPattern(string pattern, string str) {
        vector<string> ss = split(str);
        map<char, string> record;
        map<string, char> reverse;
        int sz = pattern.size();
        if (sz != ss.size())
            return false;
        for (int i = 0; i < sz; i++) {
            if (record.find(pattern[i]) == record.end())
                record[pattern[i]] = ss[i]; 
            else
                if (record[pattern[i]] != ss[i])
                    return false;
        }
        for (int i = 0; i < sz; i++) {
            if (reverse.find(ss[i]) == reverse.end())
                reverse[ss[i]] = pattern[i];
            else
                if (reverse[ss[i]] != pattern[i])
                    return false;
        }
        return true;
    }
};
