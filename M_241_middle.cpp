//
// Created by Alfred T on 2022/7/1.
// Description: 241. 为运算表达式设计优先级
//给你一个由数字和运算符组成的字符串 expression ，按不同优先级组合数字和运算符，计算并返回所有可能组合的结果。你可以 按任意顺序 返回答案。
//
//生成的测试用例满足其对应输出值符合 32 位整数范围，不同结果的数量不超过 104 。
//
//
//
//示例 1：
//
//输入：expression = "2-1-1"
//输出：[0,2]
//解释：
//((2-1)-1) = 0
//(2-(1-1)) = 2
//示例 2：
//
//输入：expression = "2*3-4*5"
//输出：[-34,-14,-10,-10,10]
//解释：
//(2*(3-(4*5))) = -34
//((2*3)-(4*5)) = -14
//((2*(3-4))*5) = -10
//(2*((3-4)*5)) = -10
//(((2*3)-4)*5) = 10
//
//
//提示：
//
//1 <= expression.length <= 20
//expression 由数字和算符 '+'、'-' 和 '*' 组成。
//输入表达式中的所有整数值在范围 [0, 99]
//

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        // START 解析expression 将数字和符号分离 符号1表示+，2表示-，3表示*
        vector<int> nums;
        vector<int> flag;
        int n = expression.length();
        int temp = 0;
        for (int i = 0; i < n; ++i) {
            char c = expression[i];
            if (c <= '9' && c >= '0') {
                temp *= 10;
                temp += (c - '0');
            } else {
                nums.push_back(temp);
                temp = 0;
                if (c == '+') {
                    flag.push_back(1);
                } else if (c == '-') {
                    flag.push_back(2);
                } else {
                    flag.push_back(3);
                }
            }
        }
        nums.push_back(temp);
        // END 解析expression

        // 开始动态规划
        vector<int> dp[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = vector<int>();
            }
        }
        for (int gap = 1; gap < n; ++gap) {
            for (int i = 0, j = i + gap; i < n && j < n; ++i, ++j) {
                dp[i][j] = vector<int>();
                // 如果就俩数字直接算
                if (gap == 1) {
                    switch (flag[i]) {
                        case 1:
                            dp[i][j].push_back(nums[i] + nums[j]);
                            break;
                        case 2:
                            dp[i][j].push_back(nums[i] - nums[j]);
                            break;
                        case 3:
                            dp[i][j].push_back(nums[i] * nums[j]);
                            break;
                    }
                } else {
                    // 如果不止两个就要慢慢算

                }
            }
        }

    }
};