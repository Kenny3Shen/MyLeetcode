/*
 * @lc app=leetcode.cn id=412 lang=cpp
 *
 * [412] Fizz Buzz
 *
 * https://leetcode-cn.com/problems/fizz-buzz/description/
 *
 * algorithms
 * Easy (64.97%)
 * Likes:    73
 * Dislikes: 0
 * Total Accepted:    48.6K
 * Total Submissions: 74.7K
 * Testcase Example:  '1'
 *
 * 写一个程序，输出从 1 到 n 数字的字符串表示。
 * 
 * 1. 如果 n 是3的倍数，输出“Fizz”；
 * 
 * 2. 如果 n 是5的倍数，输出“Buzz”；
 * 
 * 3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。
 * 
 * 示例：
 * 
 * n = 15,
 * 
 * 返回:
 * [
 * ⁠   "1",
 * ⁠   "2",
 * ⁠   "Fizz",
 * ⁠   "4",
 * ⁠   "Buzz",
 * ⁠   "Fizz",
 * ⁠   "7",
 * ⁠   "8",
 * ⁠   "Fizz",
 * ⁠   "Buzz",
 * ⁠   "11",
 * ⁠   "Fizz",
 * ⁠   "13",
 * ⁠   "14",
 * ⁠   "FizzBuzz"
 * ]
 * 
 * 
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> res;
        for (int i = 1; i <= n; i++)
        {
            if (i % 15 == 0)
                res.push_back("FizzBuzz");
            else if (i % 3 == 0)
                res.push_back("Fizz");
            else if (i % 5 == 0)
                res.push_back("Buzz");
            else
                res.push_back(to_string(i));
        }
        return res;
    }
};
// @lc code=end
