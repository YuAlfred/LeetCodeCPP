#include <iostream>
#include <vector>

using namespace std;


class TreeNode {
public:

    ~TreeNode() {
        std::cout << "析构ing" << val << std::endl;
    }

    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) { std::cout << "构造ing" << std::endl; }

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) { std::cout << "构造ing" << val << std::endl; }

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    TreeNode(const TreeNode &t) {
        this->val = t.val;
        std::cout << "拷贝构造" << val << std::endl;
    }
};

int maxLevelSum(TreeNode *root) {
    int ans = 1, maxSum = root->val;
    vector<TreeNode *> q = {root};
    for (int level = 1; !q.empty(); ++level) {
        vector<TreeNode *> nq;
        int sum = 0;
        for (auto node: q) {
            sum += node->val;
            if (node->left) {
                nq.emplace_back(node->left);
            }
            if (node->right) {
                nq.emplace_back(node->right);
            }
        }
        if (sum > maxSum) {
            maxSum = sum;
            ans = level;
        }
        q = std::move(nq);
    }
    return ans;
}

int main() {
    vector<TreeNode> test = {TreeNode(3)};
    vector<TreeNode> test2 = {TreeNode(4)};

    test2 = std::move(test);
    std::cout << test2.empty() << std::endl;

//    vector<TreeNode*> q = {root};
//    vector<TreeNode*> nq;
//    q = std::move(nq);
}