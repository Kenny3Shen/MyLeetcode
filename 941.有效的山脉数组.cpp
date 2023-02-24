/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 有效的山脉数组
 *
 * https://leetcode-cn.com/problems/valid-mountain-array/description/
 *
 * algorithms
 * Easy (36.16%)
 * Likes:    108
 * Dislikes: 0
 * Total Accepted:    46.4K
 * Total Submissions: 118.8K
 * Testcase Example:  '[2,1]'
 *
 * 给定一个整数数组 A，如果它是有效的山脉数组就返回 true，否则返回 false。
 * 
 * 让我们回顾一下，如果 A 满足下述条件，那么它是一个山脉数组：
 * 
 * 
 * A.length >= 3
 * 在 0 < i < A.length - 1 条件下，存在 i 使得：
 * 
 * A[0] < A[1] < ... A[i-1] < A[i] 
 * A[i] > A[i+1] > ... > A[A.length - 1]
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[2,1]
 * 输出：false
 * 
 * 
 * 示例 2：
 * 
 * 输入：[3,5,5]
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 输入：[0,3,2,1]
 * 输出：true
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= A.length <= 10000
 * 0 <= A[i] <= 10000 
 * 
 * 
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
    bool validMountainArray(vector<int> &A)
    {
        /* if(A.size() < 3)
            return false;
        int top = 0;;
        for (int left = 0; left < A.size() - 1; left++)
        {
            if (A[left] < A[left + 1])
                top = left + 1;
            else
                break;
        }
        if(top == A.size() - 1 || top == 0)
            return false;
        for (int right = top; right < A.size() - 1; right++)
        {
            if (A[right + 1] >= A[right])
                return false;
        }
        return true; */
        if(A.size() < 3)
            return false;
        int left = 0;
        int right = A.size() - 1;
        //从左边往右边找，一直找到山峰为止
        while (left < A.size() - 1 && A[left] < A[left + 1])
            left++;
        //从右边往左边找，一直找到山峰为止
        while (right > 0 && A[right - 1] > A[right])
            right--;
        //判断从左边和从右边找的山峰是不是同一个
        return left > 0 && right < A.size() - 1 && left == right;
    }
};
// @lc code=end
