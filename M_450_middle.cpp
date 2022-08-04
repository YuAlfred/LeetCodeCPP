//
// Created by Alfred T on 2022/6/2.
// Description: 450. 删除二叉搜索树中的节点
//给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。
//
//一般来说，删除节点可分为两个步骤：
//
//首先找到需要删除的节点；
//如果找到了，删除它。
//
//
//示例 1:
//
//
//
//输入：root = [5,3,6,2,4,null,7], key = 3
//输出：[5,4,6,2,null,null,7]
//解释：给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
//一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。
//另一个正确答案是 [5,2,6,null,4,null,7]。
//
//
//示例 2:
//
//输入: root = [5,3,6,2,4,null,7], key = 0
//输出: [5,3,6,2,4,null,7]
//解释: 二叉树不包含值为 0 的节点
//示例 3:
//
//输入: root = [], key = 0
//输出: []
//
//
//提示:
//
//节点数的范围 [0, 104].
//-105 <= Node.val <= 105
//节点值唯一
//root 是合法的二叉搜索树
//-105 <= key <= 105
//


#include <iostream>

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
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (root == nullptr) {
            return root;
        }
        // 如果key小于root就向左子树找
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        // 如果大于向右找
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        // 如果找到了
        if (root->val == key) {
            // 如果当前节点已经是叶子节点了那没事儿了 直接返回空就行了
            if (root->left == nullptr && root->right == nullptr) {
                return nullptr;
            }
            // 如果左右有一个是空的返回另一个就行了
            if (root->left == nullptr) {
                return root->right;
            }
            if (root->right == nullptr) {
                return root->left;
            }
            // 两边都不是空的 把右子树提上来，把左子树的顶作为右子树最小节点的左节点
            // 先找最小节点
            TreeNode *node = root->right;
            while (node->left != nullptr) {
                node = node->left;
            }
            // 把左子树连上去
            node->left = root->left;
            return root->right;
        }
        return nullptr;
    }
};
