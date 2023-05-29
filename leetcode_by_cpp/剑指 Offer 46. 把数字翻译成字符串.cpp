/* 给定一个数字，我们按照如下规则把它翻译为字符串：
0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

示例 1:

输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"

提示：
0 <= num < 2^31 */
class Solution
{
public:
    int translateNum(int num)
    {
        //recursive
        if (num < 10)
            return 1;
        return (num % 100 < 10 || num % 100 > 25) ? translateNum(num / 10) : translateNum(num / 10) + translateNum(num / 100);
        
        /* //从后往前
        int res = 0, one = 1, two = 1, x = 0, y = num % 10;
        while (num)
        {
            num /= 10;
            x = num % 10;
            int tmp = 10 * x + y;
            res = (tmp >= 10 && tmp <= 25) ? one + two : two;
            one = two;
            two = res;
            y = x;
        }
        return res; */

        //从前往后
        /* string str = to_string(num);
        vector<int> dp(str.size() + 1, 1);
        for (int i = 2; i <= str.size(); i++)
        {
            string sub = str.substr(i - 2, 2);
            int tmp = stoi(sub);
            if (tmp >= 10 && tmp <= 25)
                dp[i] = dp[i - 1] + dp[i - 2];
            else
                dp[i] = dp[i - 1];
        }
        return dp.back(); */

        /* if (num < 10)
            return 1;
        string str = to_string(num);
        int res = 0, one = 1, two = 1;
        for (int i = 2; i <= str.size(); i++)
        {
            string sub = str.substr(i - 2, 2);
            int tmp = stoi(sub);
            if (tmp >= 10 && tmp <= 25)
                res = one + two;
            else
                res = two;
            one = two;
            two = res;
        }
        return res; */
    }
};