/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (41.17%)
 * Likes:    1452
 * Dislikes: 0
 * Total Accepted:    232K
 * Total Submissions: 563.1K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */

// @lc code=start
#include <string>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        if (s.size() % 2)
            return false; //odd must be not Valid
        char c;
        vector<char> vecStack;
        for (char &i : s) //for(char c:chars)就是定义一个遍历字符c，
        //让它分别等于字符串数组chars里面的各个字符，然后执行下面的语句，
        //当c被赋值为chars里面所有字符各一次后，就会退出这个循环.
        {
            if (i == '}' || i == ']' || i == ')')
            {
                if (!vecStack.empty())   //栈不为空时
                    c = vecStack.back(); //c=栈顶元素
                else
                    return false;
                if ((i == '}' && c != '{') || (i == ']' && c != '[') || (i == ')' && c != '('))
                    return false; //栈顶元素匹配失败
                else
                    vecStack.pop_back(); //匹配成功，栈顶元素出栈
            }
            else
                vecStack.push_back(i); //左括号入栈
        }
        return vecStack.empty();

        /* stack<int> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                st.push(')');
            else if (s[i] == '{')
                st.push('}');
            else if (s[i] == '[')
                st.push(']');
            // 第三种情况：遍历字符串匹配的过程中，栈已经为空了，没有匹配的字符了，说明右括号没有找到对应的左括号 return false
            // 第二种情况：遍历字符串匹配的过程中，发现栈里没有我们要匹配的字符。所以return false
            else if (st.empty() || st.top() != s[i])
                return false;
            else
                st.pop(); // st.top() 与 s[i]相等，栈弹出元素
        }
        // 第一种情况：此时我们已经遍历完了字符串，但是栈不为空，说明有相应的左括号没有右括号来匹配，所以return false，否则就return true
        return st.empty(); */
    }
};
// @lc code=end
