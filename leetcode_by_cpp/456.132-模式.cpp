/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132模式
 *
 * https://leetcode-cn.com/problems/132-pattern/description/
 *
 * algorithms
 * Medium (28.72%)
 * Likes:    239
 * Dislikes: 0
 * Total Accepted:    13.5K
 * Total Submissions: 47K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个整数序列：a1, a2, ..., an，一个132模式的子序列 ai, aj, ak 被定义为：当 i < j < k 时，ai < ak <
 * aj。设计一个算法，当给定有 n 个数字的序列时，验证这个序列中是否含有132模式的子序列。
 * 
 * 注意：n 的值小于15000。
 * 
 * 示例1:
 * 
 * 
 * 输入: [1, 2, 3, 4]
 * 
 * 输出: False
 * 
 * 解释: 序列中不存在132模式的子序列。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [3, 1, 4, 2]
 * 
 * 输出: True
 * 
 * 解释: 序列中有 1 个132模式的子序列： [1, 4, 2].
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: [-1, 3, 2, 0]
 * 
 * 输出: True
 * 
 * 解释: 序列中有 3 个132模式的的子序列: [-1, 3, 2], [-1, 3, 0] 和 [-1, 2, 0].
 * 
 * 
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        //当前下标的左侧有一个比其小即可
        vector<int> leftMin(nums.size(), INT32_MAX);
        for (int i = 1; i < nums.size(); i++)
            leftMin[i] = min(leftMin[i - 1], nums[i - 1]);
        stack<int> st;
        for (int j = nums.size() - 1; j >= 0; j--)
        {
            int k = INT32_MIN;
            while (!st.empty() && st.top() < nums[j])
            {
                k = st.top();
                st.pop();
            }
            if (leftMin[j] < k)
                return true;
            st.push(nums[j]);
        }
        return false;
    }
};
// @lc code=end
