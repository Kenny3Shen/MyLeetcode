/*
 * @lc app=leetcode.cn id=480 lang=cpp
 *
 * [480] 滑动窗口中位数
 *
 * https://leetcode-cn.com/problems/sliding-window-median/description/
 *
 * algorithms
 * Hard (42.43%)
 * Likes:    213
 * Dislikes: 0
 * Total Accepted:    17.6K
 * Total Submissions: 41.1K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 中位数是有序序列最中间的那个数。如果序列的长度是偶数，则没有最中间的数；此时中位数是最中间的两个数的平均数。
 * 
 * 例如：
 * 
 * 
 * [2,3,4]，中位数是 3
 * [2,3]，中位数是 (2 + 3) / 2 = 2.5
 * 
 * 
 * 给你一个数组 nums，有一个长度为 k 的窗口从最左端滑动到最右端。窗口中有 k 个数，每次窗口向右移动 1
 * 位。你的任务是找出每次窗口移动后得到的新窗口中元素的中位数，并输出由它们组成的数组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给出 nums = [1,3,-1,-3,5,3,6,7]，以及 k = 3。
 * 
 * 
 * 窗口位置                      中位数
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       1
 * ⁠1 [3  -1  -3] 5  3  6  7      -1
 * ⁠1  3 [-1  -3  5] 3  6  7      -1
 * ⁠1  3  -1 [-3  5  3] 6  7       3
 * ⁠1  3  -1  -3 [5  3  6] 7       5
 * ⁠1  3  -1  -3  5 [3  6  7]      6
 * 
 * 
 * 因此，返回该滑动窗口的中位数数组 [1,-1,-1,3,5,6]。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 你可以假设 k 始终有效，即：k 始终小于输入的非空数组的元素个数。
 * 与真实值误差在 10 ^ -5 以内的答案将被视作正确答案。
 * 
 * 
 */
#include <set>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        vector<double> res;
        multiset<int> window(nums.begin(), nums.begin() + k);
        for (int i = k; i <= nums.size(); i++)
        {
            int mid = k / 2;
            auto iter = window.begin();
            if (k % 2 == 1)
            {
                while (mid--)
                    iter++;
                res.push_back(*iter);
            }
            else
            {
                while (mid-- != 1)
                    iter++;
                double pre = *iter++;
                res.push_back((pre + *iter) / 2);
            }
            if (i != nums.size())
            {
                auto it = window.find(nums[i - k]);
                window.erase(it);
                window.insert(nums[i]);
            }
        }
        return res;
    }
};
// @lc code=end
