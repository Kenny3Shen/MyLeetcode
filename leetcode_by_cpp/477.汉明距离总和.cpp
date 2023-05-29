/*
 * @lc app=leetcode.cn id=477 lang=cpp
 *
 * [477] 汉明距离总和
 *
 * https://leetcode-cn.com/problems/total-hamming-distance/description/
 *
 * algorithms
 * Medium (50.99%)
 * Likes:    102
 * Dislikes: 0
 * Total Accepted:    7.2K
 * Total Submissions: 14K
 * Testcase Example:  '[4,14,2]'
 *
 * 两个整数的 汉明距离 指的是这两个数字的二进制数对应位不同的数量。
 * 
 * 计算一个数组中，任意两个数之间汉明距离的总和。
 * 
 * 示例:
 * 
 * 
 * 输入: 4, 14, 2
 * 
 * 输出: 6
 * 
 * 解释: 在二进制表示中，4表示为0100，14表示为1110，2表示为0010。（这样表示是为了体现后四位之间关系）
 * 所以答案为：
 * HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2
 * + 2 + 2 = 6.
 * 
 * 
 * 注意:
 * 
 * 
 * 数组中元素的范围为从 0到 10^9。
 * 数组的长度不超过 10^4。
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    /* int hammingWeigh(long long i)
    {
        int w = 0;
        while (i)
        {
            i = i & (i - 1);
            w++;
        }
        return w;
    }*/
    int totalHammingDistance(vector<int> &nums)
    {
        /* if(nums.empty())
            return 0;
        int res = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                res += hammingWeigh(nums[i] ^ nums[j]);
            }
        }
        return res; */
        //TLE

        int n = nums.size();
        int res = 0;
        if (n == 0)
            return 0;
        vector<int> count(32, 0);
        for (auto num : nums)
        { // loop over every element
            int i = 0;
            while (num > 0)
            { // check every bit
                count[i] += (num & 1);
                num >>= 1;
                i++;
            }
        }

        for (auto k : count)
        {
            res += k * (n - k);
            //第 i位有 k个数为 1，由排列组合可知有 k * (n - k)种组合，使得汉明距离为 1
        }
        return res;
    }
};
// @lc code=end
