/*
 * @lc app=leetcode.cn id=989 lang=cpp
 *
 * [989] 数组形式的整数加法
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &A, int K)
    {
        /* int carry = 0;
        vector<int> res(A.size(), 0);

        for (int i = 0, j = A.size() - 1; i < A.size() && j >= 0; i++, j--)
        {
            int temp = K % 10 + A[j] + carry; //带上进位
            carry = temp / 10;                //是否存在进位
            K /= 10;

            res[i] = temp % 10;
        }

        K += carry; //最高位可能存在进位
        while (K)
        {
            res.push_back(K % 10);
            K /= 10;
        }
        
        reverse(res.begin(), res.end());
        return res; */

        int carry = 0;
        for(int i = A.size() - 1; i >= 0; i--)
        {
            int t = A[i] + K % 10 + carry;
            carry = t / 10;
            K /= 10;
            A[i] = t % 10;
        }
        K += carry;

        while(K)
        {
            A.insert(A.begin(), K % 10);
            K /= 10;
        }
        return A;
    }
};
// @lc code=end
