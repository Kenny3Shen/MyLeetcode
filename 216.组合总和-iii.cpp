/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 *
 * https://leetcode-cn.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (71.64%)
 * Likes:    149
 * Dislikes: 0
 * Total Accepted:    27.4K
 * Total Submissions: 38.2K
 * Testcase Example:  '3\n7'
 *
 * 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
 * 
 * 说明：
 * 
 * 
 * 所有数字都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: k = 3, n = 7
 * 输出: [[1,2,4]]
 * 
 * 
 * 示例 2:
 * 
 * 输入: k = 3, n = 9
 * 输出: [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <numeric>
using namespace std;
class Solution
{
public:
    vector<vector<int>> res;
    void backtracking(int k, int n, vector<int> &combination, int size, int begin)
    {
        //int sum = accumulate(combination.begin(), combination.end(), 0);
        /* if (size > k || sum > n)
            return; */
        if (size == k && n == 0)
        {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i < 10; i++)
        {
            if (n - i < 0) //大于 i的数都可以跳过了
                return;
            else
            {
                combination.push_back(i);
                backtracking(k, n - i, combination, size + 1, i + 1);
                combination.pop_back(); //backtracking
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> combination;
        //size为数组当前元素个数，begin为加入元素开始的值，显然数组的值是递增的
        backtracking(k, n, combination, 0, 1);
        return res;
    }
};
// @lc code=end
