#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
private:
    // 四个方向“左下右上” - 基于原坐标变化的横纵坐标
    /*int d[4][2] = {{-1, 0}, {0,1}, {1, 0}, {0, -1}};
    for (int i = 0; i < 4; i++) {
        int newx = startx + d[i][0]; // 四个横纵标
        int newy = starty + d[i][1]; // 四个纵坐标
    }*/
    // 避免贪吃蛇的自踩
    vector<vector<bool>> used;
    vector<vector<bool>> visited;

    int row, col, end;
    vector<vector<char>> array;
    string goal;
    bool checkLetter(int x, int y, int index) {
        cout << "[" << index << "] : x " << x << " y " << y << endl;
        cout << "end " << end << endl;
        // 越界
        //if ((x >= row) || (x < 0) || (y < 0) || (y >= col)) return false;
        //if (index == end) {
        if (index == end - 1) {
            cout << "[" << index << "] leaf return" << endl;
            return array[x][y] == goal[index];
        }
        if (array[x][y] == goal[index]) {
            //cout << "x : " << x << " y : " << y << " index : " << index << endl;
            used[x][y] = true;
            //cout << "here" << endl;
            if ((x+1 < row) && (used[x+1][y] == false) && checkLetter(x + 1, y, index + 1)) return true;
            if ((y+1 < col) && (used[x][y+1] == false) && checkLetter(x, y + 1, index + 1)) return true;
            if ((x-1 >= 0) && (used[x-1][y] == false) && checkLetter(x - 1, y, index + 1)) return true;
            if ((y-1 >= 0) && (used[x][y-1] == false) && checkLetter(x, y - 1, index + 1)) return true;
            used[x][y] = false;
        }
        // array[x][y] != goal[index]
        // 或在四个方向checkLetter没找到
        // 直接return就会结束递归
        cout << "[" << index << "] return" << endl;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        array = board;
        goal = word;
        row = board.size();
        col = board[0].size();
        used = vector<vector<bool>>(row, vector<bool>(col, false));
        end = word.size();
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (checkLetter(i, j, 0)) return true;
        return false;
    }
};



class Solution {
private:
    // 避免贪吃蛇的自踩
    vector<vector<bool>> used;

    int row, col, end;
    vector<vector<char>> array;
    string goal;
    bool checkLetter(int x, int y, int index) {
        // 错误的写法
        // 递归状态做结束条件，必须在最后一个状态里面做leaf的处理
        // 结束在最后一个的下一个，在一般node里处理leaf
        // 会因为leaf的下一个会发生越界导致无法执行对最后一个leaf的处理，就返回了
        // if (index == end) {
            //return true;
        // }
        if (index == end - 1) {
            return array[x][y] == goal[index];
        }
        if (array[x][y] == goal[index]) {
            used[x][y] = true;
            // 没越界 -> 可踩 -> 踩
            if ((x+1 < row) && (used[x+1][y] == false) && checkLetter(x + 1, y, index + 1)) return true;
            if ((y+1 < col) && (used[x][y+1] == false) && checkLetter(x, y + 1, index + 1)) return true;
            if ((x-1 >= 0) && (used[x-1][y] == false) && checkLetter(x - 1, y, index + 1)) return true;
            if ((y-1 >= 0) && (used[x][y-1] == false) && checkLetter(x, y - 1, index + 1)) return true;
            // 这里对往四个方向移动的坐标，有更加优雅的写法
            // 四个方向“左下右上” - 基于原坐标变化的横纵坐标
            /*int d[4][2] = {{-1, 0}, {0,1}, {1, 0}, {0, -1}};
            for (int i = 0; i < 4; i++) {
                int newx = startx + d[i][0]; // 四个横纵标
                int newy = starty + d[i][1]; // 四个纵坐标
                checkLetter(newx, newy, index + 1); // 可以统一写成是newx, newy不需要写四行了
            }*/
            used[x][y] = false;
        }
        // array[x][y] != goal[index]
        // 或在四个方向checkLetter没找到
        // 直接return就会结束递归
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        array = board;
        goal = word;
        row = board.size();
        col = board[0].size();
        used = vector<vector<bool>>(row, vector<bool>(col, false));
        end = word.size();
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (checkLetter(i, j, 0)) return true;
        return false;
    }
};

int main() {
    //string word = "ABCCED";
    //vector<vector<char>> board = {{ 'A','B','C','E' },{ 'S','F','C','S' },{ 'A','D','E','E' }};
    //cout << Solution().exist(board, word) << endl;

    string word = "a";
    vector<vector<char>> board = {{ 'a' }};
    cout << Solution().exist(board, word) << endl;
    return 0;
}
