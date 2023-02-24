/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 *
 * https://leetcode-cn.com/problems/sort-array-by-parity/description/
 *
 * algorithms
 * Easy (69.77%)
 * Likes:    188
 * Dislikes: 0
 * Total Accepted:    48.3K
 * Total Submissions: 69.2K
 * Testcase Example:  '[3,1,2,4]'
 *
 * 给定一个非负整数数组 A，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。
 * 
 * 你可以返回满足此条件的任何数组作为答案。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：[3,1,2,4]
 * 输出：[2,4,3,1]
 * 输出 [4,2,3,1]，[2,4,1,3] 和 [4,2,1,3] 也会被接受。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 5000
 * 0 <= A[i] <= 5000
 * 
 * 
 */
#include <vector>
#include <deque>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &A)
    {
        /*  deque<int> d;
        for(const int & a : A)
        {
            if(a % 2)
                d.push_back(a);
            else
                d.push_front(a);
        }   
        return vector<int>(d.begin(), d.end()); */
        int left = 0, right = A.size() - 1;
        while (left < right)
        {
            while (left < right && A[left] % 2 == 0)
                left++;
            while (left < right && A[right] % 2 == 1)
                right--;
            swap(A[left], A[right]);
        }
        return A;
    }
};
// @lc code=end
