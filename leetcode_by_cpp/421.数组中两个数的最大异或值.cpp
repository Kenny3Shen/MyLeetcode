/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 *
 * https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array/description/
 *
 * algorithms
 * Medium (61.28%)
 * Likes:    535
 * Dislikes: 0
 * Total Accepted:    44.6K
 * Total Submissions: 72.8K
 * Testcase Example:  '[3,10,5,25,2,8]'
 *
 * 给你一个整数数组 nums ，返回 nums[i] XOR nums[j] 的最大运算结果，其中 0 ≤ i ≤ j < n 。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [3,10,5,25,2,8]
 * 输出：28
 * 解释：最大运算结果是 5 XOR 25 = 28.
 *
 * 示例 2：
 *
 *
 * 输入：nums = [14,70,53,83,49,91,36,80,92,51,66,70]
 * 输出：127
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 2 * 10^5
 * 0 <= nums[i] <= 2^31 - 1
 *
 *
 *
 *
 */
#include "leetcode.h"
// @lc code=start
class TrieNode
{
private:
    TrieNode *bit[2] = {nullptr}; // 0 1

public:
    TrieNode() {}

    void insert(int &x) // 按bit存储
    {
        TrieNode *node = this;
        for (int i = 30; i >= 0; i--)
        {
            int b = x >> i & 1; //从最高位开始存储字典树
            if (!node->bit[b])
                node->bit[b] = new TrieNode();
            node = node->bit[b];
        }
    }

    int search(int &x)
    {
        TrieNode *node = this;
        int MaxXORNum = 0;
        for (int i = 30; i >= 0; i--)
        {
            MaxXORNum <<= 1;
            int b = x >> i & 1;
            // 优先选择当前位相反的路径，使得当前位异或值为1
            if (node->bit[!b]) 
            {
                node = node->bit[!b];
                MaxXORNum += !b;
            }
            else
            {
                node = node->bit[b];
                MaxXORNum += b;
            }
        }
        return MaxXORNum ^ x;
    }
};
class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        TrieNode *root = new TrieNode();
        for (int &n : nums)
            root->insert(n);
        int res = 0;
        for (int &n : nums)
            res = max(res, root->search(n));
        return res;
    }
};
// @lc code=end
