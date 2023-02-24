/*
 * @lc app=leetcode.cn id=995 lang=cpp
 *
 * [995] K 连续位的最小翻转次数
 *
 * https://leetcode-cn.com/problems/minimum-number-of-k-consecutive-bit-flips/description/
 *
 * algorithms
 * Hard (43.08%)
 * Likes:    132
 * Dislikes: 0
 * Total Accepted:    9.5K
 * Total Submissions: 18.9K
 * Testcase Example:  '[0,1,0]\n1'
 *
 * 在仅包含 0 和 1 的数组 A 中，一次 K 位翻转包括选择一个长度为 K 的（连续）子数组，同时将子数组中的每个 0 更改为 1，而每个 1 更改为
 * 0。
 * 
 * 返回所需的 K 位翻转的最小次数，以便数组没有值为 0 的元素。如果不可能，返回 -1。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：A = [0,1,0], K = 1
 * 输出：2
 * 解释：先翻转 A[0]，然后翻转 A[2]。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：A = [1,1,0], K = 2
 * 输出：-1
 * 解释：无论我们怎样翻转大小为 2 的子数组，我们都不能使数组变为 [1,1,1]。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：A = [0,0,0,1,0,1,1,0], K = 3
 * 输出：3
 * 解释：
 * 翻转 A[0],A[1],A[2]: A变成 [1,1,1,1,0,1,1,0]
 * 翻转 A[4],A[5],A[6]: A变成 [1,1,1,1,1,0,0,0]
 * 翻转 A[5],A[6],A[7]: A变成 [1,1,1,1,1,1,1,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 
 * 
 */
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) 
    {
        queue<int> que;
        int res = 0;
        for(int i = 0; i < A.size(); i++)
        {
            if(!que.empty() && i == que.front() + K)
                que.pop();
            if(que.size() % 2 == A[i])
            {
                if(i + K > A.size())
                    return -1;
                else
                {
                    que.push(i);
                    res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end

/* 
queue.front() 表示当前区间 [queue.front(), queue.front() + K) 翻转了一次
当 i 位置被翻转了偶数次，如果 A[i] 为 0，那么翻转后仍是 0，当前元素需要翻转；
当 i 位置被翻转了奇数次，如果 A[i] 为 1，那么翻转后是 0，当前元素需要翻转。
综合上面两点，我们得到一个结论，如果 len(que) % 2 == A[i] 时，当前元素需要翻转。

当 i + K > N 时，说明需要翻转大小为 K 的子区间，但是后面剩余的元素不到 K 个了，所以返回 -1。
*/