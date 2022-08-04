//
// Created by Alfred T on 2022/7/3.
// Description: 556. 下一个更大元素 III
//给你一个正整数 n ，请你找出符合条件的最小整数，其由重新排列 n 中存在的每位数字组成，并且其值大于 n 。如果不存在这样的正整数，则返回 -1 。
//
//注意 ，返回的整数应当是一个 32 位整数 ，如果存在满足题意的答案，但不是 32 位整数 ，同样返回 -1 。
//
//
//
//示例 1：
//
//输入：n = 12
//输出：21
//示例 2：
//
//输入：n = 21
//输出：-1
//
//
//提示：
//
//1 <= n <= 231 - 1
//

#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int i = s.size();
        // 从右到左找到一个变小的数字
        for (i = i - 2; i >= 0; --i) {
            if (s[i] < s[i + 1]) {
                break;
            }
        }
        if (i == -1) {
            return -1;
        }
        // 从i往后找一个比他大大最小的
        int j = i + 1;
        for (int k = j + 1; k < s.size(); ++k) {
            if (s[k] > s[i] && s[k] <= s[j]) {
                j = k;
            }
        }
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
        long ans = stol(s);
        return ans > INT_MAX ? -1 : (int) ans;
    }
};