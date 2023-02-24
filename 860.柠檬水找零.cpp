/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0, ten = 0, twenty = 0;
        for (int const &bill : bills)
        {
            if (bill == 5)
                five++; //直接收下
            else if (bill == 10)
            {
                if (five <= 0)
                    return false;
                else
                {
                    ten++;  //增加一个10
                    five--; //消耗一个5
                }
            }
            else
            {
                // 优先消耗10美元，因为5美元的找零用处更大，能多留着就多留着
                if (five > 0 && ten > 0)
                {
                    five--;
                    ten--;
                    twenty++; // 其实这行代码可以删了，因为记录20已经没有意义了，不会用20来找零
                }
                else if (five >= 3)
                {
                    five -= 3;
                    twenty++; // 同理，这行代码也可以删了
                }
                else
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end
/* 
情况一：账单是5，直接收下。
情况二：账单是10，消耗一个5，增加一个10
情况三：账单是20，优先消耗一个10和一个5，如果不够，在消耗三个5 
*/