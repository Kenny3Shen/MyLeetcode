/*
 * @lc app=leetcode.cn id=961 lang=cpp
 *
 * [961] 重复 N 次的元素
 *
 * https://leetcode-cn.com/problems/n-repeated-element-in-size-2n-array/description/
 *
 * algorithms
 * Easy (66.82%)
 * Likes:    86
 * Dislikes: 0
 * Total Accepted:    27.6K
 * Total Submissions: 41.2K
 * Testcase Example:  '[1,2,3,3]'
 *
 * 在大小为 2N 的数组 A 中有 N+1 个不同的元素，其中有一个元素重复了 N 次。
 * 
 * 返回重复了 N 次的那个元素。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[1,2,3,3]
 * 输出：3
 * 
 * 
 * 示例 2：
 * 
 * 输入：[2,1,2,5,3,2]
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 输入：[5,1,5,2,5,3,5,4]
 * 输出：5
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 4 <= A.length <= 10000
 * 0 <= A[i] < 10000
 * A.length 为偶数
 * 
 * 
 */
#include <vector>
#include <numeric>
using namespace std;
// @lc code=start
class Solution
{
public:
    int repeatedNTimes(vector<int> &A)
    {
        for (int i = 0; i < A.size() - 1; ++i)
            if (A[i] == A[i + 1])
                return A[i];
        if (A[0] == A[2] || A[0] == A[3])
            return A[0];
        return A[1];
    }
};
/* 整个数组中没有连续出现相同数字的情况：前4个也不可能有连续相等，
所以一定是 3 X 3 X 或者 3 X X 3 或者 X 3 X 3 的其中一种，
因此只需要判断A[0] == A[2] || A[0] == A[3] true就返回A[0]，否则就是A[1]==A[3]返回A[1]。 */

// @lc code=end
