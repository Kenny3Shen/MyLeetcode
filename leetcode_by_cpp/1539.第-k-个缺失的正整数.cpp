/*
 * @lc app=leetcode.cn id=1539 lang=cpp
 *
 * [1539] 第 k 个缺失的正整数
 *
 * https://leetcode-cn.com/problems/kth-missing-positive-number/description/
 *
 * algorithms
 * Easy (54.95%)
 * Likes:    5
 * Dislikes: 0
 * Total Accepted:    3.6K
 * Total Submissions: 6.6K
 * Testcase Example:  '[2,3,4,7,11]\n5'
 *
 * 给你一个 严格升序排列 的正整数数组 arr 和一个整数 k 。
 * 
 * 请你找到这个数组里第 k 个缺失的正整数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = [2,3,4,7,11], k = 5
 * 输出：9
 * 解释：缺失的正整数包括 [1,5,6,8,9,10,12,13,...] 。第 5 个缺失的正整数为 9 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：arr = [1,2,3,4], k = 2
 * 输出：6
 * 解释：缺失的正整数包括 [5,6,7,...] 。第 2 个缺失的正整数为 6 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length <= 1000
 * 1 <= arr[i] <= 1000
 * 1 <= k <= 1000
 * 对于所有 1 <= i < j <= arr.length 的 i 和 j 满足 arr[i] < arr[j] 
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int cnt = 0, i = 1, j = 0;
        while (cnt != k)    //双指针遍历
        {
            if (i != arr[j])
            {
                cnt++;
                i++;
            }
            else
            {
                i++;
                if (j != arr.size() - 1)
                    j++;
            }
        }
        return i - 1;
    }
};
// @lc code=end
