/*
 * @lc app=leetcode.cn id=1442 lang=cpp
 *
 * [1442] 形成两个异或相等数组的三元组数目
 *
 * https://leetcode-cn.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/
 *
 * algorithms
 * Medium (67.37%)
 * Likes:    132
 * Dislikes: 0
 * Total Accepted:    24.4K
 * Total Submissions: 31K
 * Testcase Example:  '[2,3,1,6,7]'
 *
 * 给你一个整数数组 arr 。
 * 
 * 现需要从数组中取三个下标 i、j 和 k ，其中 (0 <= i < j <= k < arr.length) 。
 * 
 * a 和 b 定义如下：
 * 
 * 
 * a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
 * b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
 * 
 * 
 * 注意：^ 表示 按位异或 操作。
 * 
 * 请返回能够令 a == b 成立的三元组 (i, j , k) 的数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：arr = [2,3,1,6,7]
 * 输出：4
 * 解释：满足题意的三元组分别是 (0,1,2), (0,2,2), (2,3,4) 以及 (2,4,4)
 * 
 * 
 * 示例 2：
 * 
 * 输入：arr = [1,1,1,1,1]
 * 输出：10
 * 
 * 
 * 示例 3：
 * 
 * 输入：arr = [2,3]
 * 输出：0
 * 
 * 
 * 示例 4：
 * 
 * 输入：arr = [1,3,5,7,9]
 * 输出：3
 * 
 * 
 * 示例 5：
 * 
 * 输入：arr = [7,11,12,9,5,2,7,17,22]
 * 输出：8
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length <= 300
 * 1 <= arr[i] <= 10^8
 * 
 * 
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    int countTriplets(vector<int> &arr)
    {
        int n = arr.size(), ans = 0;
        vector<int> pre(n + 1);
        for (int i = 1; i <= n; ++i)
            pre[i] = pre[i - 1] ^ arr[i - 1];
        for (int i = 1; i <= n; ++i)
            for (int k = i + 1; k <= n; ++k)
                if (pre[i - 1] == pre[k])
                    ans += k - i;
        // a == b => a ^ b = 0
        // arr[i] ^...^ arr[j-1] ^ arr[j] ^...^ arr[k] = 0
        // pre[i - 1] = pre[k]
        // arr[0] ^ ... ^ arr[i - 1] == arr[0] ^ ... ^ arr[i - 1] ^ arr[i] ^ ... ^ arr[k]
        return ans;
    }
};
// @lc code=end
