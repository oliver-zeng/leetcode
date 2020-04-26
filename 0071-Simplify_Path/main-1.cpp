class Solution {
private:
static void split(const string& s, vector<string>& tokens, const string& delimiters = " ")
{
        string::size_type lastPos = s.find_first_not_of(delimiters, 0);
        string::size_type pos = s.find_first_of(delimiters, lastPos);
        while (string::npos != pos || string::npos != lastPos) {
                tokens.push_back(s.substr(lastPos, pos - lastPos));
                lastPos = s.find_first_not_of(delimiters, pos);
                pos = s.find_first_of(delimiters, lastPos);
        }
}
public:
    string simplifyPath(string path) {
        vector<string> token;
        split(path, token, "/");
        vector<string> record;
        string res = "";
        for (auto elm : token) {
            if (elm == ".") {
                continue;
            } else if (elm == "..") {
                if (!record.empty()) {
                    record.pop_back();
                }
            } else if (elm != "") {
                record.push_back(elm);
            }
        }
        for (auto elm : record)
            res += "/" + elm;
        // 最后要补上record为空，什么都没有时就是根目录"/"
        if (res == "")
            res = "/";
        return res;
    }
};
