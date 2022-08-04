//
// Created by Alfred T on 2022/5/31.
// Description: 剑指 Offer II 114. 外星文字典
//现有一种使用英语字母的外星文语言，这门语言的字母顺序与英语顺序不同。
//
//给定一个字符串列表 words ，作为这门语言的词典，words 中的字符串已经 按这门新语言的字母顺序进行了排序 。
//
//请你根据该词典还原出此语言中已知的字母顺序，并 按字母递增顺序 排列。若不存在合法字母顺序，返回 "" 。若存在多种可能的合法字母顺序，返回其中 任意一种 顺序即可。
//
//字符串 s 字典顺序小于 字符串 t 有两种情况：
//
//在第一个不同字母处，如果 s 中的字母在这门外星语言的字母顺序中位于 t 中字母之前，那么 s 的字典顺序小于 t 。
//如果前面 min(s.length, t.length) 字母都相同，那么 s.length < t.length 时，s 的字典顺序也小于 t 。
//
//
//示例 1：
//
//输入：words = ["wrt","wrf","er","ett","rftt"]
//输出："wertf"
//示例 2：
//
//输入：words = ["z","x"]
//输出："zx"
//示例 3：
//
//输入：words = ["z","x","z"]
//输出：""
//解释：不存在合法字母顺序，因此返回 "" 。
//
//
//提示：
//
//1 <= words.length <= 100
//1 <= words[i].length <= 100
//words[i] 仅由小写英文字母组成
//
//
//注意：本题与主站 269 题相同： https://leetcode-cn.com/problems/alien-dictionary/
//


#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // 记录每个字符的下一个字符
    unordered_map<char, vector<char>> edges;
    // 记录每个字符的入度
    unordered_map<char, int> ingress;
    // 是否无环，有环则无法成功
    bool valid = true;

    string alienOrder(vector<string> &words) {
        int n = words.size();
        // 遍历字典，初始化边信息
        for (string &word: words) {
            for (int i = 0; i < word.length(); ++i) {
                char c = word[i];
                if (edges.count(c) == 0) {
                    edges[c] = vector<char>();
                }
            }
        }

        // 添加边和入度信息
        for (int i = 0; i < words.size() - 1; ++i) {
            addEdges(words[i], words[i + 1]);
        }

        if (!valid) {
            return "";
        }

        // 用队列记录入度为0的节点
        queue<char> qu;
        // 用string记录最终结果
        string ans;

        // 选出入度为0的节点加入队列
        for (auto [node, _]: edges) {
            if (ingress.count(node) == 0) {
                qu.push(node);
            }
        }

        // 依次pop出入度为0的节点加入ans，同时相邻节点入度减1
        while (!qu.empty()) {
            char c = qu.front();
            qu.pop();
            ans.push_back(c);
            for (const auto &node: edges[c]) {
                ingress[node]--;
                if (ingress[node] == 0) {
                    qu.push(node);
                }
            }
        }

        return ans.size() == edges.size() ? ans : "";
    }

    void addEdges(string before, string after) {
        int n = min(before.length(), after.length());
        int index = 0;
        while (index < n) {
            // 如果不一致就记录，如果一致就继续
            if (before[index] != after[index]) {
                edges[before[index]].push_back(after[index]);
                ingress[after[index]]++;
                break;
            }
            index++;
        }
        if (index == n && before.length() > after.length()) {
            valid = false;
        }
    }

};


int main() {
    Solution s;
    vector<string> v;
    v.push_back("test");
    s.alienOrder(v);
}