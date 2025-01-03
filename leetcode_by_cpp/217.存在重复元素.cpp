/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 *
 * https://leetcode-cn.com/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (52.38%)
 * Likes:    273
 * Dislikes: 0
 * Total Accepted:    153.2K
 * Total Submissions: 290.4K
 * Testcase Example:  '[1,2,3,1]'
 *
 * 给定一个整数数组，判断是否存在重复元素。
 * 
 * 如果任意一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3,1]
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入: [1,2,3,4]
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: [1,1,1,3,3,4,3,2,4,2]
 * 输出: true
 * 
 */

// @lc code=start
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        /*unordered_map<int, int> map;
        for (int i : nums)
        {
            map[i]++;       //key对应的value++，默认为0
            if (map[i] > 1)//value >= 2,既纯真重复元素
                return true;
        }
        return false;*/
        return nums.size() > unordered_set<int>(nums.begin(),nums.end()).size();
    }
};
// @lc code=end
