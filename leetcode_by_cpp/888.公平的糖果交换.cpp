// @before-stub-for-debug-begin
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=888 lang=cpp
 *
 * [888] 公平的糖果交换
 *
 * https://leetcode-cn.com/problems/fair-candy-swap/description/
 *
 * algorithms
 * Easy (55.82%)
 * Likes:    128
 * Dislikes: 0
 * Total Accepted:    36.7K
 * Total Submissions: 58.7K
 * Testcase Example:  '[1,1]\n[2,2]'
 *
 * 爱丽丝和鲍勃有不同大小的糖果棒：A[i] 是爱丽丝拥有的第 i 根糖果棒的大小，B[j] 是鲍勃拥有的第 j 根糖果棒的大小。
 * 
 * 因为他们是朋友，所以他们想交换一根糖果棒，这样交换后，他们都有相同的糖果总量。（一个人拥有的糖果总量是他们拥有的糖果棒大小的总和。）
 * 
 * 返回一个整数数组 ans，其中 ans[0] 是爱丽丝必须交换的糖果棒的大小，ans[1] 是 Bob 必须交换的糖果棒的大小。
 * 
 * 如果有多个答案，你可以返回其中任何一个。保证答案存在。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：A = [1,1], B = [2,2]
 * 输出：[1,2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：A = [1,2], B = [2,3]
 * 输出：[1,2]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：A = [2], B = [1,3]
 * 输出：[2,3]
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：A = [1,2,5], B = [2,4]
 * 输出：[5,4]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 1 
 * 1 
 * 保证爱丽丝与鲍勃的糖果总量不同。
 * 答案肯定存在。
 * 
 * 
 */
#include <vector>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> fairCandySwap(vector<int> &A, vector<int> &B)
    {
        int sum1 = 0, sum2 = 0;
        unordered_set<int> set1, set2;
        for (auto const &a : A)
        {
            sum1 += a;
            set1.insert(a);
        }
        for (auto const &b : B)
        {
            sum2 += b;
            set2.insert(b);
        }
        int mean = (sum1 + sum2) >> 1;
        for (auto const &s : set1) // A change s
        {
            int need = mean - (sum1 - s); // B change need
            if (set2.find(need) != set2.end())
                return {s, need};
        }
        return {0, 0};
    }
};
// @lc code=end
