//
// Created by ty on 2022/9/3.
// 给定一个二叉树的 root ，返回 最长的路径的长度 ，这个路径中的 每个节点具有相同值 。 这条路径可以经过也可以不经过根节点。
//
//两个节点之间的路径长度 由它们之间的边数表示。
//
// 
//
//示例 1:
//
//
//
//输入：root = [5,4,5,1,1,5]
//输出：2
//示例 2:
//
//
//
//输入：root = [1,4,5,4,4,5]
//输出：2
// 
//
//提示:
//
//树的节点数的范围是 [0, 104] 
//-1000 <= Node.val <= 1000
//树的深度将不超过 1000 
//
//来源：力扣（LeetCode）
//链接：https://leetcode.cn/problems/longest-univalue-path
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


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
    int longestUnivaluePath(TreeNode *root) {
        dfs(root);
        return _ans;
    }

private:
    int dfs(TreeNode *root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);

        int cur = 0;
        int single_path = 0;
        if (root->left != nullptr && root->val == root->left->val) {
            cur += left + 1;
            single_path = max(single_path, left + 1);
        }
        if (root->right != nullptr && root->val == root->right->val) {
            cur += right + 1;
            single_path = max(single_path, right + 1);
        }
        _ans = max(_ans, cur);
        return single_path;
    }

private:
    int _ans = 0;

};
