/*
 * @lc app=leetcode.cn id=1694 lang=cpp
 *
 * [1694] 重新格式化电话号码
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string reformatNumber(string number)
    {
        string res;
        int cnt = 0;
        for (int i = 0; i < number.size(); i++)
        {
            if (number[i] == ' ' || number[i] == '-')
                continue;
            else
            {
                res.push_back(number[i]);
                cnt++;
                if (cnt % 3 == 0)  //忽略尾部细节，每逢三个数字就加一个'-'
                {
                    res.push_back('-');
                    cnt = 0;
                }
            }
        }
        if (res.back() == '-') //删除最后的'-'，实际上就是size % 3 == 0 的情况
            res.pop_back();

        //其实对于最后一个'-'，我们只关心它后面跟了几个数字
        //因为最后一个'-'前面一定是3为一组的
        //若最后一个'-'后面只跟了一个数字，我们把最后一个'-'前面的一个数字移到'-'后面，这样就是3-2-2的合法格式
        int newSize = res.size();
        if (res[newSize - 2] == '-') 
            swap(res[newSize - 2], res[newSize - 3]);

        return res;
    }
};
// @lc code=end
