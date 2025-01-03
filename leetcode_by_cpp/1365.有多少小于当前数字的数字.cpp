/*
 * @lc app=leetcode.cn id=1365 lang=cpp
 *
 * [1365] 有多少小于当前数字的数字
 *
 * https://leetcode-cn.com/problems/how-many-numbers-are-smaller-than-the-current-number/description/
 *
 * algorithms
 * Easy (82.10%)
 * Likes:    43
 * Dislikes: 0
 * Total Accepted:    22.6K
 * Total Submissions: 27.5K
 * Testcase Example:  '[8,1,2,2,3]'
 *
 * 给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。
 * 
 * 换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] < nums[i] 。
 * 
 * 以数组形式返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [8,1,2,2,3]
 * 输出：[4,0,1,1,3]
 * 解释： 
 * 对于 nums[0]=8 存在四个比它小的数字：（1，2，2 和 3）。 
 * 对于 nums[1]=1 不存在比它小的数字。
 * 对于 nums[2]=2 存在一个比它小的数字：（1）。 
 * 对于 nums[3]=2 存在一个比它小的数字：（1）。 
 * 对于 nums[4]=3 存在三个比它小的数字：（1，2 和 2）。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [6,5,4,8]
 * 输出：[2,1,0,3]
 * 
 * 
 * 示例 3：
 * 
 * 输入：nums = [7,7,7,7]
 * 输出：[0,0,0,0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= nums.length <= 500
 * 0 <= nums[i] <= 100
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
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    { //bucket count
        /* vector<int> bucket(102, 0);     
        for (auto num : nums)
            bucket[num + 1]++;

        for (int i = 1; i < bucket.size(); i++)
            bucket[i] += bucket[i - 1];

        for (int i = 0; i < nums.size(); i++)
            nums[i] = bucket[nums[i]];
        
        return nums; */
        vector<int> vec = nums;
        sort(vec.begin(), vec.end()); // 从小到大排序之后，元素下标就是小于当前数字的数字
        int hash[101];
        for (int i = vec.size() - 1; i >= 0; i--)
        { // 从后向前，记录 vec[i] 对应的下表
            hash[vec[i]] = i;
        }
        // 此时hash里保存的每一个元素数值 对应的 小于这个数值的个数
        for (int i = 0; i < nums.size(); i++)
        {
            vec[i] = hash[nums[i]];
        }
        return vec;
    }
};
// @lc code=end
