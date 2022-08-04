//
// Created by Alfred T on 2022/5/27.
// Description: 190. 颠倒二进制位
// 颠倒给定的 32 位无符号整数的二进制位。
//
//提示：
//
//请注意，在某些语言（如 Java）中，没有无符号整数类型。在这种情况下，输入和输出都将被指定为有符号整数类型，并且不应影响您的实现，因为无论整数是有符号的还是无符号的，其内部的二进制表示形式都是相同的。
//在 Java 中，编译器使用二进制补码记法来表示有符号整数。因此，在 示例 2 中，输入表示有符号整数 -3，输出表示有符号整数 -1073741825。
// 
//
//示例 1：
//
//输入：n = 00000010100101000001111010011100
//输出：964176192 (00111001011110000010100101000000)
//解释：输入的二进制串 00000010100101000001111010011100 表示无符号整数 43261596，
//     因此返回 964176192，其二进制表示形式为 00111001011110000010100101000000。
//示例 2：
//
//输入：n = 11111111111111111111111111111101
//输出：3221225471 (10111111111111111111111111111111)
//解释：输入的二进制串 11111111111111111111111111111101 表示无符号整数 4294967293，
//     因此返回 3221225471 其二进制表示形式为 10111111111111111111111111111111 。
// 
//
//提示：
//
//输入是一个长度为 32 的二进制字符串
// 
//
//进阶: 如果多次调用这个函数，你将如何优化你的算法？
//
//来源：力扣（LeetCode）
//链接：https://leetcode.cn/problems/reverse-bits
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
//

#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
    // 方法1 逐位运算
    uint32_t reverseBits1(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; ++i) {
            ans <<= 1;
            ans |= (n & 1);
            n >>= 1;
        }
        return ans;
    }

    // 方法2 位运算分治
    uint32_t reverseBits2(uint32_t n) {
        cout << "二进制： " << bitset<sizeof(n) * 8>(n) << endl;

        uint32_t b1 = 0b01010101010101010101010101010101;
        uint32_t b2 = 0b00110011001100110011001100110011;
        uint32_t b4 = 0b00001111000011110000111100001111;
        uint32_t b8 = 0b00000000111111110000000011111111;

        // 首先对其两两奇偶位交换
        n = (n & b1) << 1 | (n >> 1 & b1);
        // 然后两两交换
        n = (n & b2) << 2 | (n >> 2 & b2);
        // 然后四四交换
        n = (n & b4) << 4 | (n >> 4 & b4);
        // 然后八八交换
        n = (n & b8) << 8 | (n >> 8 & b8);
        // 然后十六十六交换
        n = (n << 16) | (n >> 16);
        return n;
    }
};

int main() {
    Solution *s = new Solution();
    uint32_t g = 100;
    int a = s->reverseBits2(g);
    std::cout << a << std::endl;
}