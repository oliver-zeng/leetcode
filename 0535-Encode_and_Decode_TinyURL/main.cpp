class Solution {
    using ull = unsigned long long;
    const string code = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_map<string, string> map;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        ull num;
        // Hascode转化为n进制
        // 将 string 的每一位转换为固定质数的进制
        // 将 string 转换为 hash value
        for (int i = 0; i < longUrl.size(); i++)
            num = num * 5 + longUrl[i];
        // 这题要返回的是一个string类型的key
        // 所以还需要把这个hash value再转成一个string
        // 把数字按新的字母表长度len辗转相除得到一组新的数字
        // 将每次得到的新数字 % len 对应到这个字母表中的一个字母
        string res;
        int len = code.size();
        if (num) {
            res += code[num % len];
            num /= len;
        }
        // 最后记得map这个key与其真正代表的字符串
        map[res] = longUrl;
        return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return map[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));