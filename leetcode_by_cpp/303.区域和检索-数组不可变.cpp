/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 *
 * https://leetcode-cn.com/problems/range-sum-query-immutable/description/
 *
 * algorithms
 * Easy (61.78%)
 * Likes:    163
 * Dislikes: 0
 * Total Accepted:    41.5K
 * Total Submissions: 67.1K
 * Testcase Example:  '["NumArray","sumRange","sumRange","sumRange"]\n' +
  '[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * 给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。
 * 
 * 示例：
 * 
 * 给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()
 * 
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * 
 * 说明:
 * 
 * 
 * 你可以假设数组不可变。
 * 会多次调用 sumRange 方法。
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class NumArray
{
private:
    vector<int> sum; //前缀和数组
public:
    NumArray(vector<int> &nums)
    {
        sum.resize(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++)
            sum[i + 1] = sum[i] + nums[i];
    }

    int sumRange(int i, int j)
    {
        return sum[j + 1] - sum[i]; //前 j 个元素和减去 前 i - 1元素和
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end
