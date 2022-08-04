//
// Created by Alfred T on 2022/7/4.
// Description: 1200. 最小绝对差
//给你个整数数组 arr，其中每个元素都 不相同。
//
//请你找到所有具有最小绝对差的元素对，并且按升序的顺序返回。
//
//
//
//示例 1：
//
//输入：arr = [4,2,1,3]
//输出：[[1,2],[2,3],[3,4]]
//示例 2：
//
//输入：arr = [1,3,6,10,15]
//输出：[[1,3]]
//示例 3：
//
//输入：arr = [3,8,-10,23,19,-4,-14,27]
//输出：[[-14,-10],[19,23],[23,27]]
//
//
//提示：
//
//2 <= arr.length <= 10^5
//-10^6 <= arr[i] <= 10^6
//

#include <vector>
//#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int minDiff = arr[1] - arr[0];
        for (int i = 0; i < n - 1; ++i) {
            int curDiff = arr[i + 1] - arr[i];
            if (curDiff < minDiff) {
                minDiff = curDiff;
                ans.clear();
                ans.push_back(vector<int>{arr[i], arr[i + 1]});
            } else if (curDiff == minDiff) {
                ans.push_back(vector<int>{arr[i], arr[i + 1]});
            }
        }
        return ans;
    }
};