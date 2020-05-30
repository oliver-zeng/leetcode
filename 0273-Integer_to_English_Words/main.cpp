class Solution {
    // 让index与英文数字完全对齐，空的字串正对着输出时为空的
    // c++不能 T [] = {} 写在类成员，[]里必须有数字
    const string thousand[4] = {"", "Thousand", "Million", "Billion"};
    const string less_twenty[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    const string ten[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string less_thousand(int num) {
        string res = "";
        if (num == 0) return res;
        if (num >= 100)// 这里一定要有=，包含100
            res = less_twenty[num / 100] + " Hundred ";
        if (num % 100 < 20)
        	res += less_twenty[num % 100];
        else
            res += ten[(num / 10) % 10] + " " + less_twenty[num % 10]; // 这里less_twenty可能为空
        // 所以最后要删除可能的多余空格
        while(res[res.size() - 1] == ' ') res.pop_back();
        //cout << res << endl;
        return res;
	}
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        int index = 0;
        string res = "";
        while (num > 0) {
            string tmp = less_thousand(num % 1000);
            if (!tmp.empty()) // tmp 可能为空，此时不能加上 thousand
            	res = tmp + " " + thousand[index] + " " + res; // 这里res与thousand可能为空
            num /= 1000;
            index++;
        }
        // 所以最后要删除可能的多余空格
        while(res[res.size() - 1] == ' ') res.pop_back();
        return res;
    }
};