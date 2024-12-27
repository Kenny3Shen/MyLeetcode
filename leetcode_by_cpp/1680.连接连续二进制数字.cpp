/*
 * @lc app=leetcode.cn id=1680 lang=cpp
 *
 * [1680] 连接连续二进制数字
 */

// @lc code=start
class Solution
{
private:
    static constexpr int mod = 1000000007;

public:
    int concatenatedBinary(int n)
    {
        int ans = 0;
        int shift = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (!(i & (i - 1)))
            {
                ++shift;
            }
            ans = ((static_cast<long long>(ans) << shift) + i) % mod;
        }
        return ans;
    }
};
/* 模的四则运算：
(a + b) % p = (a % p + b % p) % p
(a - b) % p = (a % p - b % p ) % p
(a * b) % p = (a % p * b % p) % p
a ^ b % p = ((a % p)^b) % p
结合律：
((a+b) % p + c) % p = (a + (b+c) % p) % p
((ab) % p * c)% p = (a * (bc) % p) % p
交换律：
(a + b) % p = (b+a) % p
(a * b) % p = (b * a) % p
分配律：
(a+b) % p = ( a % p + b % p ) % p
((a +b)% p * c) % p = ((a * c) % p + (b * c) % p) % p */
// @lc code=end
