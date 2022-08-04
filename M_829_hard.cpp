//
// Created by Alfred T on 2022/6/3.
// Description: 829. 连续整数求和
//给定一个正整数 n，返回 连续正整数满足所有数字之和为 n 的组数 。
//
//
//
//示例 1:
//
//输入: n = 5
//输出: 2
//解释: 5 = 2 + 3，共有两组连续整数([5],[2,3])求和后为 5。
//示例 2:
//
//输入: n = 9
//输出: 3
//解释: 9 = 4 + 5 = 2 + 3 + 4
//示例 3:
//
//输入: n = 15
//输出: 4
//解释: 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
//
//
//提示:
//
//1 <= n <= 109​​​​​​​
//

#include <iostream>
#include "climits"

using namespace std;

class Solution {
public:

    /*
     * 解析：
     * 通过求和公式可以转换为x = n/k - (k-1)/2
     * */

    int consecutiveNumbersSum(int n) {
        // k从1遍历到根号2n
        int k = 1;
        int right = (int) sqrt(2 * n);
        int ans = 0;
        while (k <= right) {
            // 奇数
            if (k & 1 == 1) {
                if (n % k == 0) {
                    ans++;
                }
            } else {
                // 偶数
                if (n % k != 0 && (2 * n) % k == 0) {
                    ans++;
                }
            }
            k++;
        }
        return ans;
    }


};

int main() {
    std::cout << INT32_MAX << std::endl;
    std::cout << LONG_MAX << std::endl;
    Solution s;
    std::cout << s.consecutiveNumbersSum(15) << std::endl;
//    s.consecutiveNumbersSum(15);

    return 0;
}