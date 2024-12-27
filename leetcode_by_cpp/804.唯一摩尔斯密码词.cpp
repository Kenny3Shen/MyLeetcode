/*
 * @lc app=leetcode.cn id=804 lang=cpp
 *
 * [804] 唯一摩尔斯密码词
 *
 * https://leetcode-cn.com/problems/unique-morse-code-words/description/
 *
 * algorithms
 * Easy (74.84%)
 * Likes:    127
 * Dislikes: 0
 * Total Accepted:    28.4K
 * Total Submissions: 37.7K
 * Testcase Example:  '["gin", "zen", "gig", "msg"]'
 *
 * 国际摩尔斯密码定义一种标准编码方式，将每个字母对应于一个由一系列点和短线组成的字符串， 比如: "a" 对应 ".-", "b" 对应 "-...",
 * "c" 对应 "-.-.", 等等。
 * 
 * 为了方便，所有26个英文字母对应摩尔斯密码表如下：
 * 
 * 
 * [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
 * 
 * 给定一个单词列表，每个单词可以写成每个字母对应摩尔斯密码的组合。例如，"cab" 可以写成 "-.-..--..."，(即 "-.-." + ".-"
 * + "-..." 字符串的结合)。我们将这样一个连接过程称作单词翻译。
 * 
 * 返回我们可以获得所有词不同单词翻译的数量。
 * 
 * 例如:
 * 输入: words = ["gin", "zen", "gig", "msg"]
 * 输出: 2
 * 解释: 
 * 各单词翻译如下:
 * "gin" -> "--...-."
 * "zen" -> "--...-."
 * "gig" -> "--...--."
 * "msg" -> "--...--."
 * 
 * 共有 2 种不同翻译, "--...-." 和 "--...--.".
 * 
 * 
 * 
 * 
 * 注意:
 * 
 * 
 * 单词列表words 的长度不会超过 100。
 * 每个单词 words[i]的长度范围为 [1, 12]。
 * 每个单词 words[i]只包含小写字母。
 * 
 * 
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        string str[26] = {".-", "-...", "-.-.", "-..", ".", "..-.",
                          "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",
                          ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_map<char, string> map;
        for (int i = 0; i < 26; i++)
            map['a' + i] = str[i]; //establish mapping
        string temp;
        unordered_set<string> set;
        for (auto w : words)
        {
            for (auto c : w)
                temp += map[c];
            set.insert(temp); //deduplicate
            temp = "";        //initialize
        }
        return set.size();
    }
};
// @lc code=end
