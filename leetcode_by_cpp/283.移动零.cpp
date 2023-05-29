/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 *
 * https://leetcode-cn.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (61.13%)
 * Likes:    614
 * Dislikes: 0
 * Total Accepted:    159.3K
 * Total Submissions: 260.5K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,3,12]
 * 输出: [1,3,12,0,0]
 * 
 * 说明:
 * 
 * 
 * 必须在原数组上操作，不能拷贝额外的数组。
 * 尽量减少操作次数。
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
        {
            if (nums[fastIndex] != 0)
            {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        // 将slowIndex之后的冗余元素赋值为0
        for (int i = slowIndex; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }
    /* stable_partition(nums.begin(),nums.end(),[&](int a){
            return a != 0;
        }); */
};
// @lc code=end
