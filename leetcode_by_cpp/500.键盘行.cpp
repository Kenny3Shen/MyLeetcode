/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 *
 * https://leetcode-cn.com/problems/keyboard-row/description/
 *
 * algorithms
 * Easy (69.67%)
 * Likes:    105
 * Dislikes: 0
 * Total Accepted:    19.6K
 * Total Submissions: 28.1K
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * 给定一个单词列表，只返回可以使用在键盘同一行的字母打印出来的单词。键盘如下图所示。
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 输入: ["Hello", "Alaska", "Dad", "Peace"]
 * 输出: ["Alaska", "Dad"]
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 你可以重复使用键盘上同一字符。
 * 你可以假设输入的字符串将只包含字母。
 * 
 */
#include <vector>
#include <map>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {
        map<char, int> map1 = {{'q', 0}, {'w', 0}, {'e', 0}, {'r', 0}, {'t', 0}, {'y', 0}, {'u', 0}, {'i', 0}, {'o', 0}, {'p', 0}, {'a', 1}, {'s', 1}, {'d', 1}, {'f', 1}, {'g', 1}, {'h', 1}, {'j', 1}, {'k', 1}, {'l', 1}, {'z', 2}, {'x', 2}, {'c', 2}, {'v', 2}, {'b', 2}, {'n', 2}, {'m', 2}, {'Q', 0}, {'W', 0}, {'E', 0}, {'R', 0}, {'T', 0}, {'Y', 0}, {'U', 0}, {'I', 0}, {'O', 0}, {'P', 0}, {'A', 1}, {'S', 1}, {'D', 1}, {'F', 1}, {'G', 1}, {'H', 1}, {'J', 1}, {'K', 1}, {'L', 1}, {'Z', 2}, {'X', 2}, {'C', 2}, {'V', 2}, {'B', 2}, {'N', 2}, {'M', 2}};
        vector<string> vec; //存放最终结果
        string str;         //暂存中间某个字符串
        int k, flat;
        for (int i = 0; i < words.size(); i++)
        {
            str = words[i];
            k = map1[str[0]]; //获取首字母所在的行
            if (str.size() == 1)
                vec.push_back(str); //只有一个字母的特例
            else
            {
                flat = 0;
                for (int j = 1; j < str.size(); j++)
                {
                    if (map1[str[j]] != k)
                    {
                        flat = 1;
                        break;
                    }
                }
                if (flat == 0)
                    vec.push_back(str); //若每个字符都在k行，则将此字符串存入vec中
            }
        }
        return vec;
    }
};
// @lc code=end
