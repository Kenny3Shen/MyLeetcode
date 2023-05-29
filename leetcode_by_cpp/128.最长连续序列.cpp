/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode.cn/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (55.12%)
 * Likes:    1407
 * Dislikes: 0
 * Total Accepted:    319.2K
 * Total Submissions: 579.1K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 *
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0,3,7,2,5,8,4,6,0,1]
 * 输出：9
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * -10^9
 *
 *
 */
#include "leetcode.h"
// @lc code=start
class UnionFind
{
private:
    unordered_map<int, int> parent;
    //unordered_map<int, int> size;

public:
    UnionFind(vector<int> &nums)
    {
        for (auto n : nums)
        {
            parent[n] = n;
            //size[n] = 1;
        }
    }

    int Find(int x)
    {
        if (parent[x] == x)
            return x;
        parent[x] = Find(parent[x]);
        return parent[x];
    }

    void Union(int x, int y)
    {
        if (parent.find(y) != parent.end()) // 以y = x + 1为x的parent
        {
            parent[x] = y;
        }
    }


};
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() < 2)
            return nums.size();
        UnionFind uf(nums);
        for (auto n : nums)
            uf.Union(n, n + 1);
        int res = 1;
        for (auto n : nums)
            res = max(res, uf.Find(n) - n + 1);
        return res;
    }
};
// @lc code=end
