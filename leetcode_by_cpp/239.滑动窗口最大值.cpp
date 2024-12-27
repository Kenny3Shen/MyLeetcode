/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 *
 * https://leetcode-cn.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (49.13%)
 * Likes:    629
 * Dislikes: 0
 * Total Accepted:    87.9K
 * Total Submissions: 179K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k
 * 个数字。滑动窗口每次只向右移动一位。
 * 
 * 返回滑动窗口中的最大值。
 * 
 * 
 * 
 * 进阶：
 * 
 * 你能在线性时间复杂度内解决此题吗？
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
 * 输出: [3,3,5,5,6,7] 
 * 解释: 
 * 
 * ⁠ 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 * 
 * 
 */
#include <deque>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        /* //TLE
        if (nums.empty() || k > nums.size() || k <= 0)
            return {};
        vector<int> res;
        int start = 0;
        int end = k; //左闭右开
        while (end != nums.size() + 1)
        {
            int temp = INT_MIN;
            for (int i = start; i < end; i++)
            {
                temp = max(temp, nums[i]);
            }
            res.push_back(temp);
            start++, end++;
        }
        return res; */

        if (nums.empty() || k > nums.size() || k <= 0)
        {
            return {};
        }
        vector<int> res;
        deque<int> findMax;
        for (int i = 0; i < nums.size(); ++i)
        {
            // i 每加一次，代表滑动窗口向右移一个单位。
            // i 指向的是每个滑动窗口的尾部元素（从 i = k - 1 开始）。
            if (i >= k && !findMax.empty())
            {
                // i >= k 是为了确保 findMax.front() 至少为第一个完整的滑动窗口的最大值索引。
                // 即至少形成了一个完整的滑动窗口。
                res.push_back(nums[findMax.front()]);
            }
            while (!findMax.empty() && nums[i] >= nums[findMax.back()])
            {
                // 如果新进来的 nums[i] 大于等于滑动窗口的尾部元素，
                // 说明该尾部元素肯定不会是任何滑动窗口的最大元素。
                // 就想象公司新来了一个既比你年轻又比你能干（大于等于你）的人，那你就只能被淘汰了，
                // 而且是循环淘汰掉所有不如新员工的老员工。
                findMax.pop_back();
            }
            if (!findMax.empty() && i - findMax.front() >= k)
            {
                // 虽然 findMax 的头部是最大的元素的索引，但是如果当前滑动窗口已不包括该索引，
                // 那么需要弹出该索引。
                // 就想象即使是公司的骨干成员，但是过了35岁也要被淘汰。
                findMax.pop_front();
            }
            findMax.push_back(i);
        }
        res.push_back(nums[findMax.front()]); // 最后一个滑动窗口还没计算就退出了 for 循环，需补上。
        return res;
    }
};
// @lc code=end
