/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 *
 * https://leetcode-cn.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (55.42%)
 * Likes:    644
 * Dislikes: 0
 * Total Accepted:    134.5K
 * Total Submissions: 238.8K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 * 
 * 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
 * 
 * 注意:
 * 不能使用代码库中的排序函数来解决这道题。
 * 
 * 示例:
 * 
 * 输入: [2,0,2,1,1,0]
 * 输出: [0,0,1,1,2,2]
 * 
 * 进阶：
 * 
 * 
 * 一个直观的解决方案是使用计数排序的两趟扫描算法。
 * 首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
 * 你能想出一个仅使用常数空间的一趟扫描算法吗？
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        // all in [0, zero] = 0
        // all in (zero, i) = 1
        // all in (two, len - 1] = 2

        int zero = -1;
        int two = nums.size() - 1;
        int i = 0;

        while (i <= two)
        {
            if (nums[i] == 0)
            {
                zero++;
                swap(nums[zero], nums[i]);
                i++;
            }
            else if (nums[i] == 1)
            {
                i++;
            }
            else
            {
                swap(nums[i], nums[two]);
                two--;
            }
        }
    }
};
// @lc code=end
