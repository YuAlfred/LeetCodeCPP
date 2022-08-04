//
// Created by Alfred T on 2022/5/29.
// Description: 468. 验证IP地址
// 给定一个字符串 queryIP。如果是有效的 IPv4 地址，返回 "IPv4" ；如果是有效的 IPv6 地址，返回 "IPv6" ；如果不是上述类型的 IP 地址，返回 "Neither" 。
//
//有效的IPv4地址 是 “x1.x2.x3.x4” 形式的IP地址。 其中 0 <= xi <= 255 且 xi 不能包含 前导零。例如: “192.168.1.1” 、 “192.168.1.0” 为有效IPv4地址， “192.168.01.1” 为无效IPv4地址; “192.168.1.00” 、 “192.168@1.1” 为无效IPv4地址。
//
//一个有效的IPv6地址 是一个格式为“x1:x2:x3:x4:x5:x6:x7:x8” 的IP地址，其中:
//
//1 <= xi.length <= 4
//xi 是一个 十六进制字符串 ，可以包含数字、小写英文字母( 'a' 到 'f' )和大写英文字母( 'A' 到 'F' )。
//在 xi 中允许前导零。
//例如 "2001:0db8:85a3:0000:0000:8a2e:0370:7334" 和 "2001:db8:85a3:0:0:8A2E:0370:7334" 是有效的 IPv6 地址，而 "2001:0db8:85a3::8A2E:037j:7334" 和 "02001:0db8:85a3:0000:0000:8a2e:0370:7334" 是无效的 IPv6 地址。
//
// 
//
//示例 1：
//
//输入：queryIP = "172.16.254.1"
//输出："IPv4"
//解释：有效的 IPv4 地址，返回 "IPv4"
//示例 2：
//
//输入：queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
//输出："IPv6"
//解释：有效的 IPv6 地址，返回 "IPv6"
//示例 3：
//
//输入：queryIP = "256.256.256.256"
//输出："Neither"
//解释：既不是 IPv4 地址，又不是 IPv6 地址
// 
//
//提示：
//
//queryIP 仅由英文字母，数字，字符 '.' 和 ':' 组成。
//
//来源：力扣（LeetCode）
//链接：https://leetcode.cn/problems/validate-ip-address
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
//

#include <iostream>
//#include <string.h>

using namespace std;

class Solution {

private:

    bool isIPV4(string queryIP) {
        // 通过长度剪枝
        int n = queryIP.length();
        if (n < 7 || n > 15) {
            return false;
        }
        // 暂时记录点号前的数字
        int preNum = 0;
        // 点的个数
        int pNum = 0;
        // 依次遍历
        for (int i = 0; i < n; ++i) {
            char c = queryIP.at(i);
            // 如果不是 .
            if (c != '.') {
                // 如果非数字则错误
                if (c > '9' || c < '0') {
                    return false;
                }
                // 如果c是第一个数字且后面再无数字且c为0则错误
                if (c == '0' && preNum == 0 && i != n - 1 && queryIP.at(i + 1) != '.') {
                    return false;
                }
                // 暂存c
                preNum *= 10;
                preNum += (c - '0');

            } else {
                // 如果是.
                // 点的个数加一
                pNum++;
                if (pNum > 3) {
                    return false;
                }
                // 前置数字判断并归零
                if (i != 0 && queryIP.at(i - 1) == '.') {
                    return false;
                }
                if (preNum > 255 || preNum < 0) {
                    return false;
                }
                preNum = 0;
            }
        }
        // 最后再判断一下
        if (pNum != 3) {
            return false;
        }
        if (preNum > 255 || preNum < 0) {
            return false;
        }
        return true;
    }

    bool isIPV6(string queryIP) {
        // 长度剪枝
        int n = queryIP.length();
        if (n < 15 || n > 39) {
            return false;
        }
        // 冒号数量统计
        int count = 0;
        // 冒号前的数字位数
        int preNum = 0;
        // 遍历每一个字符
        for (int i = 0; i < n; ++i) {
            char c = queryIP.at(i);
            // 如果c不是冒号
            if (c != ':') {
                // c必须满足十六进制
                if ((c <= '9' && c >= '0') || (c <= 'f' && c >= 'a') || (c <= 'F' && c >= 'A')) {
                    // 如果满足十六进制，数字位数加一
                    preNum++;
                    if (preNum > 4) {
                        return false;
                    }
                } else {
                    // 如果不满足十六进制 返回错误
                    return false;
                }
            } else {
                // 如果c是冒号
                // 前面必须有数字
                if (preNum == 0) {
                    return false;
                }
                preNum = 0;
                count++;
            }
        }
        // 最后判断一下冒号数量
        if (count != 7) {
            return false;
        }
        if (preNum == 0) {
            return false;
        }
        return true;
    }

public:

    string validIPAddress(string queryIP) {
        // 粗略判断是v4还是v6
        if (queryIP.find('.') != string::npos) {
            // 如果有.就走v4判断
            if (isIPV4(queryIP)) {
                return "IPv4";
            }
        } else {
            // 如果没有.就走v6判断
            if (isIPV6(queryIP)) {
                return "IPv6";
            }
        }
        return "Neither";
    }

};

int main() {
    Solution s;
    std::cout << s.validIPAddress("192.168.@2.1") << std::endl;
    return 0;
}