//
// Created by ty on 2022/8/22.
// 655. 输出二叉树
//给你一棵二叉树的根节点 root ，请你构造一个下标从 0 开始、大小为 m x n 的字符串矩阵 res ，用以表示树的 格式化布局 。构造此格式化布局矩阵需要遵循以下规则：
//
//树的 高度 为 height ，矩阵的行数 m 应该等于 height + 1 。
//矩阵的列数 n 应该等于 2height+1 - 1 。
//根节点 需要放置在 顶行 的 正中间 ，对应位置为 res[0][(n-1)/2] 。
//对于放置在矩阵中的每个节点，设对应位置为 res[r][c] ，将其左子节点放置在 res[r+1][c-2height-r-1] ，右子节点放置在 res[r+1][c+2height-r-1] 。
//继续这一过程，直到树中的所有节点都妥善放置。
//任意空单元格都应该包含空字符串 "" 。
//返回构造得到的矩阵 res 。
//
//
//
//
//
//示例 1：
//
//
//输入：root = [1,2]
//输出：
//[["","1",""],
// ["2","",""]]
//示例 2：
//
//
//输入：root = [1,2,3,null,4]
//输出：
//[["","","","1","","",""],
// ["","2","","","","3",""],
// ["","","4","","","",""]]
//
//
//提示：
//
//树中节点数在范围 [1, 210] 内
//-99 <= Node.val <= 99
//树的深度在范围 [1, 10] 内


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<vector<string>> printTree(TreeNode *root) {
        // 先找二叉树高度
        _height = 0;
        deque<TreeNode *> line;
        line.push_back(root);
        while (!line.empty()) {
            ++_height;
            int size = line.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *node = line.front();
                line.pop_front();
                if (node->left != nullptr) {
                    line.push_back(node->left);
                }
                if (node->right != nullptr) {
                    line.push_back(node->right);
                }
            }
        }

        // 构造数组
        int cols = pow(2, _height) - 1; // 矩阵的列数
        vector<vector<string>> ans(_height, vector<string>(cols, ""));
        dfs(ans, root, 0, 0, cols - 1);

        return ans;
    }

    void dfs(vector<vector<string>> &ans, TreeNode *node, int row, int start, int end) {
        if (node == nullptr) {
            return;
        }
        int col = start + (end - start) / 2;
        ans[row][col] = to_string(node->val);
        dfs(ans, node->left, row + 1, start, col - 1);
        dfs(ans, node->right, row + 1, col + 1, end);
    }

private:
    int _height;
};
