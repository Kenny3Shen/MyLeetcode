/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (54.25%)
 * Likes:    847
 * Dislikes: 0
 * Total Accepted:    148.4K
 * Total Submissions: 272.8K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
private:
    /* unordered_map<char, string> map = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, 
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}}; */
    string map[10] = {{""}, {""}, {"abc"}, {"def"}, {"ghi"}, 
    {"jkl"}, {"mno"}, {"pqrs"}, {"tuv"}, {"wxyz"}};
    vector<string> res;
    string combination; //combination.size() == digits.size()

public:
    void backtracking(string digits, int curLength)
    {
        if (curLength == digits.size()) //combination.size() == curLength
        {
            res.push_back(combination);
            return;
        }
        //string curMap = map[digits[curLength]]; //当前数字的映射
        string curMap = map[digits[curLength] - '0'];
        for (int i = 0; i < curMap.size(); i++)
        {
            combination.push_back(curMap[i]);
            backtracking(digits, curLength + 1);
            combination.pop_back(); //backtrack
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return res;
        else
            backtracking(digits, 0);
        return res;
    }
};
// @lc code=end
