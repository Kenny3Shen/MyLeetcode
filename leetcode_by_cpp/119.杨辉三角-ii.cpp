/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode-cn.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (60.39%)
 * Likes:    130
 * Dislikes: 0
 * Total Accepted:    44.9K
 * Total Submissions: 74.2K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: [1,3,3,1]
 * 
 * 
 * 进阶：
 * 
 * 你可以优化你的算法到 O(k) 空间复杂度吗？
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
//C(n,k)=n! / (n-k)!*k! = n*(n-1)*...*(n-k+1)! / k!
//C(n,k)= n*(n-1)*...*(n-k+2) / (k-1)! * (n-k+1) / k
//      =C(n,k-1)*(n-k+1) / k
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> vec(1);
        vec[0] = 1;
        long pre = 1;
        for (int k = 1; k <= rowIndex; k++)
        {
            long cur = pre * (rowIndex - k + 1) / k;
            vec.push_back(static_cast<int>(cur));
            pre = cur;
        }
        return vec;
    }
};
// @lc code=end
