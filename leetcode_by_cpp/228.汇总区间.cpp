/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 *
 * https://leetcode-cn.com/problems/summary-ranges/description/
 *
 * algorithms
 * Easy (53.90%)
 * Likes:    73
 * Dislikes: 0
 * Total Accepted:    15.8K
 * Total Submissions: 29.4K
 * Testcase Example:  '[0,1,2,4,5,7]'
 *
 * 给定一个无重复元素的有序整数数组 nums 。
 * 
 * 返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表。也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，并且不存在属于某个范围但不属于
 * nums 的数字 x 。
 * 
 * 列表中的每个区间范围 [a,b] 应该按如下格式输出：
 * 
 * 
 * "a->b" ，如果 a != b
 * "a" ，如果 a == b
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [0,1,2,4,5,7]
 * 输出：["0->2","4->5","7"]
 * 解释：区间范围是：
 * [0,2] --> "0->2"
 * [4,5] --> "4->5"
 * [7,7] --> "7"
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [0,2,3,4,6,8,9]
 * 输出：["0","2->4","6","8->9"]
 * 解释：区间范围是：
 * [0,0] --> "0"
 * [2,4] --> "2->4"
 * [6,6] --> "6"
 * [8,9] --> "8->9"
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = []
 * 输出：[]
 * 
 * 
 * 示例 4：
 * 
 * 输入：nums = [-1]
 * 输出：["-1"]
 * 
 * 
 * 示例 5：
 * 
 * 输入：nums = [0]
 * 输出：["0"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= nums.length <= 20
 * -2^31 <= nums[i] <= 2^31 - 1
 * nums 中的所有值都 互不相同
 * 
 * 
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{ //nums 中的所有值都 互不相同
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> res;
        if (nums.empty())
            return res;

        int start = nums[0];
        int end = nums[0];
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i + 1] - 1 != nums[i]) //[-2147483648,-2147483647,2147483647]
            {
                if (start == end)
                    res.push_back(to_string(start));
                else
                    res.push_back(to_string(start) + "->" + to_string(end));

                start = nums[i + 1];
                end = nums[i + 1];
            }
            else
            {
                end = nums[i + 1];
            }
        }

        if (start == end)
            res.push_back(to_string(start));
        else
            res.push_back(to_string(start) + "->" + to_string(end));
        return res;
    }
};
// @lc code=end
