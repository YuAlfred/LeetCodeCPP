#include <string>
#include <vector>
#include <iostream>

//
// Created by Alfred T on 2022/5/17.
// Description:
//

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

int main() {
    Solution s;
    vector<int> p = {1, 2, 3, 4, 5, 6};
    std::cout << s.twoSum(p, 4)[0] << std::endl;
}
