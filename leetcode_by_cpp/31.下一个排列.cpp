/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 *
 * https://leetcode-cn.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (34.61%)
 * Likes:    717
 * Dislikes: 0
 * Total Accepted:    96.4K
 * Total Submissions: 278.5K
 * Testcase Example:  '[1,2,3]'
 *
 * 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 * 
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 * 
 * 必须原地修改，只允许使用额外常数空间。
 * 
 * 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        //next_permutation(nums.begin(), nums.end());
        int i = 0;
        for (i = nums.size() - 2; i >= 0; i--)
        { // 从后往前找到第一个相邻升序对
            if (nums[i] < nums[i + 1])
                break;
        }

        if (i == -1)
            reverse(nums.begin(), nums.end()); // 无相邻升序对，必定为非递减序列
        else
        {
            for (int j = nums.size() - 1; j >= i + 1; j--)
            { // 从后往前[i+1,end)找第一个大于a[i+1]的值
                if (nums[i] < nums[j])
                {
                    swap(nums[i], nums[j]);                    // 交换二者
                    reverse(nums.begin() + i + 1, nums.end()); // 反转[i+1,end)，变成升序
                    //等同于 sort(nums.begin() + i + 1, nums.end());
                    break;
                }
            }
        }
    }
};
// @lc code=end
