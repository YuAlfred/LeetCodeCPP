//
// Created by Alfred T on 2022/6/14.
// Description: 498. 对角线遍历
//给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。
//
//
//
//示例 1：
//
//
//输入：mat = [[1,2,3],[4,5,6],[7,8,9]]
//输出：[1,2,4,7,5,3,6,8,9]
//示例 2：
//
//输入：mat = [[1,2],[3,4]]
//输出：[1,2,3,4]
//
//
//提示：
//
//m == mat.length
//n == mat[i].length
//1 <= m, n <= 104
//1 <= m * n <= 104
//-105 <= mat[i][j] <= 105
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 方法1 速度很慢
    vector<int> findDiagonalOrder1(vector<vector<int>> &mat) {
        // m行n列
        int m = mat.size();
        int n = mat[0].size();
        // 维护一个每一行的指针数组
        vector<int> p(m);
        for (int i = 0; i < m; ++i) {
            p[i] = -i;
        }
        bool downToUp = true;
        vector<int> ans;
        int len = m * n;
        while (ans.size() < len) {
            if (downToUp) {
                for (int i = m - 1; i >= 0; --i) {
                    if (p[i] >= 0 && p[i] < n) {
                        ans.push_back(mat[i][p[i]]);
                    }
                    p[i]++;
                }
                downToUp = false;
            } else {
                for (int i = 0; i < m; ++i) {
                    if (p[i] >= 0 && p[i] < n) {
                        ans.push_back(mat[i][p[i]]);
                    }
                    p[i]++;
                }
                downToUp = true;
            }
        }
        return ans;
    }

    // 方法二
    vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
        // m行n列
        int m = mat.size();
        int n = mat[0].size();
        int len = m * n;
        vector<int> ans;
        ans.push_back(mat[0][0]);
        int i = 0, j = 0;
        // 先从左下到右上
        bool downToUp = true;
        while (true) {
            if (downToUp) {
                //先尝试往右上走
                if (isLegal(i - 1, j + 1, m, n)) {
                    // 可行就走
                    i--;
                    j++;
                    ans.push_back(mat[i][j]);
                    // 不然就尝试向右走并转变方向
                } else if (isLegal(i, j + 1, m, n)) {
                    j++;
                    ans.push_back(mat[i][j]);
                    downToUp ^= true;
                    // 再不行就尝试向下走并转变方向
                } else if (isLegal(i + 1, j, m, n)) {
                    i++;
                    ans.push_back(mat[i][j]);
                    downToUp ^= true;
                    // 再不行就到头了
                } else {
                    break;
                }
            } else {
                // 先尝试往左下走
                if (isLegal(i + 1, j - 1, m, n)) {
                    i++;
                    j--;
                    ans.push_back(mat[i][j]);
                    // 不然就尝试向下走并转变方向
                } else if (isLegal(i + 1, j, m, n)) {
                    i++;
                    ans.push_back(mat[i][j]);
                    downToUp ^= true;
                    // 不然就尝试向右走并转变方向
                } else if (isLegal(i, j + 1, m, n)) {
                    j++;
                    ans.push_back(mat[i][j]);
                    downToUp ^= true;
                    // 再不行就到头了
                } else {
                    break;
                }
            }
        }
        return ans;
    }

    bool isLegal(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
};

int main() {

    Solution s;
    vector<vector<int>> p;
    vector<int> t;
    t.push_back(2);
    t.push_back(3);
    p.push_back(t);
    auto ans = s.findDiagonalOrder(p);
    std::cout << "test" << std::endl;
}