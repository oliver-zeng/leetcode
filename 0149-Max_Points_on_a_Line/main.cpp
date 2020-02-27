class Solution {
private:
    int gcd( int a , int b ){
        return b ? gcd(b, a % b) : a;
    }

    // 不损失精度，记录相同斜率方法
    pair<int,int> slope( const vector<int> &pa, const vector<int> &pb ) {
        // 斜率 k = (y1 - y2) / (x1 - x2)
        // 有除法会损失精度，导致无法判断相等
        // 所以直接记录 (y1 - y2) 与 (x1 - x2) 来表示斜率
        // 这里面有三个问题需要解决
        int dy = pa[1] - pb[1];
        int dx = pa[0] - pb[0];

        // 问题二：
        // 在轴上的点，无法用 x % 0 求模，因此没法用辗转相除得gcd
        // 为他们规定统一的斜率表示
        if( dx == 0 )
            return make_pair(1,0);
        if( dy == 0 )
            return make_pair(0,1);

        // 问题一：
        // 同一个 k 可由不同的 (y1 - y2) 与 (x1 - x2) 相除得到
        // 所以要让二者同时除以他们的最大公约数gcd，得到相同的系数
        int g = gcd( abs(dy), abs(dx) );
        dy /= g;
        dx /= g;

        // 问题三：
        // (y1 - y2) 与 (x1 - x2) 有4个正负号组合
        // 但实际只会产生两种斜率，因此规定其中一个为正
        // 把这4个符合组合，转换为两种斜率表示
        if( dx < 0 ){
            dy = -dy;
            dx = -dx;
        }

        return make_pair( dy , dx );
    }

public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() <= 1)
            return points.size();
        int res = 0;
        // 这题需要每个点，与其他点都要找一下斜率
        // 不能因为j出现在i后面，就不考虑points[j]与points[i]相连的情况
        // 但是record统计的斜率，必须是以每个点为轴单算的
        // 不能相互打架，因此record的定义必须要放到第一重循环里面
        for (int i = 0; i < points.size(); i++) {
            // key不能是pair类型，将pair表示成值为
            // "pair.first#pair.second"的string
            unordered_map<string, int> record;
            int same_point = 0;
            for (int j = 0; j < points.size(); j++) {
                if (points[i] == points[j]) {
                    same_point++;
                    continue;
                }
                pair<int, int> kp = slope(points[i], points[j]);
                string k = to_string(kp.first) + "#" + to_string(kp.second);
                record[k]++;
            }
            // [[0, 0], [0, 0]]走不进record循环，same_point加不上
            // 若res就是same_points的话，就会漏解
            res = max(res, same_point);
            for (auto p : record) {
                int count = p.second + same_point;
                res = count > res ? count : res;
            }
        }
   
        return res;
    }
};