/*
 * @lc app=leetcode.cn id=1078 lang=cpp
 *
 * [1078] Bigram 分词
 *
 * https://leetcode-cn.com/problems/occurrences-after-bigram/description/
 *
 * algorithms
 * Easy (61.74%)
 * Likes:    18
 * Dislikes: 0
 * Total Accepted:    8.5K
 * Total Submissions: 13.7K
 * Testcase Example:  '"alice is a good girl she is a good student"\n"a"\n"good"'
 *
 * 给出第一个词 first 和第二个词 second，考虑在某些文本 text 中可能以 "first second third" 形式出现的情况，其中
 * second 紧随 first 出现，third 紧随 second 出现。
 * 
 * 对于每种这样的情况，将第三个词 "third" 添加到答案中，并返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：text = "alice is a good girl she is a good student", first = "a", second
 * = "good"
 * 输出：["girl","student"]
 * 
 * 
 * 示例 2：
 * 
 * 输入：text = "we will we will rock you", first = "we", second = "will"
 * 输出：["we","rock"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= text.length <= 1000
 * text 由一些用空格分隔的单词组成，每个单词都由小写英文字母组成
 * 1 <= first.length, second.length <= 10
 * first 和 second 由小写英文字母组成
 * 
 * 
 */
#include <vector>
#include <string>
#include <sstream>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> findOcurrences(string text, string first, string second)
    {
        istringstream words(text);
        string w;
        vector<string> tmp, ans;
        while (words >> w)
            tmp.push_back(w);
        for (int i = 0, j = 1; j < tmp.size() - 1; ++i, ++j)
            if (tmp[i] == first && tmp[j] == second)
                ans.push_back(tmp[j + 1]);

        return ans;
    }
};
// @lc code=end
