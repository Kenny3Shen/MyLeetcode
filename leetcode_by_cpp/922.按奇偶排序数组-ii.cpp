/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 *
 * https://leetcode-cn.com/problems/sort-array-by-parity-ii/description/
 *
 * algorithms
 * Easy (68.48%)
 * Likes:    132
 * Dislikes: 0
 * Total Accepted:    40.3K
 * Total Submissions: 58.9K
 * Testcase Example:  '[4,2,5,7]'
 *
 * 给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。
 * 
 * 对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。
 * 
 * 你可以返回任何满足上述条件的数组作为答案。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：[4,2,5,7]
 * 输出：[4,5,2,7]
 * 解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= A.length <= 20000
 * A.length % 2 == 0
 * 0 <= A[i] <= 1000
 * 
 * 
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &a)
    {
        /* int size = a.size();
        vector<int> odd(size / 2);
        vector<int> even(size / 2);
        for (auto n : a)
            n % 2 ? odd.push_back(n) : even.push_back(n);
        for (int i = 0; i < size; i += 2)
        {
            a[i] = even.back();
            a[i + 1] = odd.back();
            odd.pop_back();
            even.pop_back();
        }
        return a; */

        
    }
};
// @lc code=end
