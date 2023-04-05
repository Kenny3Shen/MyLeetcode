/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 *
 * https://leetcode-cn.com/problems/increasing-subsequences/description/
 *
 * algorithms
 * Medium (48.92%)
 * Likes:    167
 * Dislikes: 0
 * Total Accepted:    20.5K
 * Total Submissions: 37.5K
 * Testcase Example:  '[4,6,7,7]'
 *
 * 给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。
 * 
 * 示例:
 * 
 * 
 * 输入: [4, 6, 7, 7]
 * 输出: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7],
 * [4,7,7]]
 * 
 * 说明:
 * 
 * 
 * 给定数组的长度不会超过15。
 * 数组中的整数范围是 [-100,100]。
 * 给定数组中可能包含重复数字，相等的数字应该被视为递增的一种情况。
 * 
 * 
 */
#include <vector>
#include <set>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        dfs(nums, 0);
        vector<vector<int>> res(st.begin(), st.end());
        return res;
    }

    void dfs(vector<int> &nums, int curIndex)
    {
        if (curIndex >= nums.size()) 
        {
            if (cur.size() > 1)
                st.insert(cur);
            return;
        }
 
        //遍历 O(2^n)
        //选择curIndex
        if (cur.empty() || nums[curIndex] >= cur.back())
        {
            cur.push_back(nums[curIndex]);
            dfs(nums, curIndex + 1);
            cur.pop_back(); //backtracking
        }
        //不选curIndex
        dfs(nums, curIndex + 1);
    }

private:
    vector<int> cur;     //当前子序列
    set<vector<int>> st; //de-duplicate
};

// @lc code=end
