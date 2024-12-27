/*
 * @lc app=leetcode.cn id=992 lang=cpp
 *
 * [992] K 个不同整数的子数组
 *
 * https://leetcode-cn.com/problems/subarrays-with-k-different-integers/description/
 *
 * algorithms
 * Hard (33.13%)
 * Likes:    234
 * Dislikes: 0
 * Total Accepted:    14.5K
 * Total Submissions: 35.7K
 * Testcase Example:  '[1,2,1,2,3]\n2'
 *
 * 给定一个正整数数组 A，如果 A 的某个子数组中不同整数的个数恰好为 K，则称 A 的这个连续、不一定独立的子数组为好子数组。
 * 
 * （例如，[1,2,3,1,2] 中有 3 个不同的整数：1，2，以及 3。）
 * 
 * 返回 A 中好子数组的数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：A = [1,2,1,2,3], K = 2
 * 输出：7
 * 解释：恰好由 2 个不同整数组成的子数组：[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2],
 * [1,2,1,2].
 * 
 * 
 * 示例 2：
 * 
 * 输入：A = [1,2,1,3,4], K = 3
 * 输出：3
 * 解释：恰好由 3 个不同整数组成的子数组：[1,2,1,3], [2,1,3], [1,3,4].
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 20000
 * 1 <= A[i] <= A.length
 * 1 <= K <= A.length
 * 
 * 
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numOfSubarrayWithMaxKDistinct(const vector<int> &A, int K)
    {
        int i = 0, j = 0;
        int res = 0, distinct = 0;
        unordered_map<int, int> umap;
        while (j < A.size())
        {
            if (umap[A[j]] == 0)
                distinct++;
            umap[A[j]]++;
            while (distinct > K)
            {
                umap[A[i]]--;
                if (umap[A[i]] == 0)
                    distinct--;
                i++;
            }
            res += j - i + 1;
            j++;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int> &A, int K)
    {
        return numOfSubarrayWithMaxKDistinct(A, K) - numOfSubarrayWithMaxKDistinct(A, K - 1);
    }
};
//恰好由 K 个不同整数的子数组的个数 = 最多由 K 个不同整数的子数组的个数 - 最多由 K - 1 个不同整数的子数组的个数
// @lc code=end
