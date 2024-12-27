/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (69.22%)
 * Likes:    961
 * Dislikes: 0
 * Total Accepted:    100.8K
 * Total Submissions: 145.6K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: 5
 * 解释:
 * 给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int numTrees(int n) 
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // null tree
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
// dp[i] += for j in [1, i] the number of BST when element j is the headnode 
//       = dp[the number of left subBST when element j is the headnode] 
//         + dp[the number of right subBST when element j is the headnode]
//       = dp[j - 1] * dp[i - j]  (have j - 1 elements smaller than j, have i - j elements bigger than j)
// @lc code=end

