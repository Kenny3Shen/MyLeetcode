/*
 * @lc app=leetcode.cn id=1295 lang=cpp
 *
 * [1295] 统计位数为偶数的数字
 *
 * https://leetcode-cn.com/problems/find-numbers-with-even-number-of-digits/description/
 *
 * algorithms
 * Easy (82.26%)
 * Likes:    43
 * Dislikes: 0
 * Total Accepted:    28.9K
 * Total Submissions: 35.3K
 * Testcase Example:  '[12,345,2,6,7896]'
 *
 * 给你一个整数数组 nums，请你返回其中位数为 偶数 的数字的个数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [12,345,2,6,7896]
 * 输出：2
 * 解释：
 * 12 是 2 位数字（位数为偶数） 
 * 345 是 3 位数字（位数为奇数）  
 * 2 是 1 位数字（位数为奇数） 
 * 6 是 1 位数字 位数为奇数） 
 * 7896 是 4 位数字（位数为偶数）  
 * 因此只有 12 和 7896 是位数为偶数的数字
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [555,901,482,1771]
 * 输出：1 
 * 解释： 
 * 只有 1771 是位数为偶数的数字。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 500
 * 1 <= nums[i] <= 10^5
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0,count=0;
        for(auto i : nums)
        {
            while(i)
            {
                i /= 10;
                count++;
            }
            if(count % 2 == 0)
                ans++;
            count = 0;
        }
        return ans;
    }
};
// @lc code=end

