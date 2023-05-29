/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 *
 * https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Easy (54.15%)
 * Likes:    308
 * Dislikes: 0
 * Total Accepted:    98.9K
 * Total Submissions: 182.5K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
 * 
 * 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
 * 
 * 说明:
 * 
 * 
 * 返回的下标值（index1 和 index2）不是从零开始的。
 * 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
 * 
 * 
 * 示例:
 * 
 * 输入: numbers = [2, 7, 11, 15], target = 9
 * 输出: [1,2]
 * 解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size()-1;
        vector<int> ans;
        while(i < j)
        {
            if(numbers[i] + numbers[j] ==target)
            {
                ans.push_back(i+1);
                ans.push_back(j+1);
                return ans;
            }
            else if(numbers[i] + numbers[j] > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }   
        return ans;
    }
};
/*
使用双指针，一个指针指向值较小的元素，一个指针指向值较大的元素。
指向较小元素的指针从头向尾遍历，指向较大元素的指针从尾向头遍历。
如果两个指针指向元素的和 sum == targetsum==target，那么得到要求的结果；
如果 sum > targetsum>target，移动较大的元素，使 sumsum 变小一些；
如果 sum < targetsum<target，移动较小的元素，使 sumsum 变大一些。
*/
// @lc code=end

