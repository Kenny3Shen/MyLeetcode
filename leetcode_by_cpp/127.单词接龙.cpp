/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 *
 * https://leetcode-cn.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (44.01%)
 * Likes:    588
 * Dislikes: 0
 * Total Accepted:    77.5K
 * Total Submissions: 172.9K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord
 * 的最短转换序列的长度。转换需遵循如下规则：
 * 
 * 
 * 每次转换只能改变一个字母。
 * 转换过程中的中间单词必须是字典中的单词。
 * 
 * 
 * 说明:
 * 
 * 
 * 如果不存在这样的转换序列，返回 0。
 * 所有单词具有相同的长度。
 * 所有单词只由小写字母组成。
 * 字典中不存在重复的单词。
 * 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * 输出: 5
 * 
 * 解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * ⁠    返回它的长度 5。
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * 输出: 0
 * 
 * 解释: endWord "cog" 不在字典中，所以无法进行转换。
 * 
 */
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        // 将vector转成unordered_set，提高查询速度
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        // 如果endWord没有在wordSet出现，直接返回0
        if (wordSet.find(endWord) == wordSet.end())
            return 0;

        // 记录word是否访问过
        unordered_map<string, int> visitMap; // <word, 查询到这个word路径长度>

        // 初始化队列 (BFS使用队列数据结构)
        queue<string> que;
        que.push(beginWord);

        // 初始化visitMap
        visitMap.insert(pair<string, int>(beginWord, 1));
        //visitMap.insert(make_pair(beginWord, 1));
        //visitMap.insert({beginWord, 1});

        while (!que.empty())
        {
            string word = que.front();
            que.pop();
            int path = visitMap[word]; // 这个word的路径长度
            for (int i = 0; i < word.size(); i++)
            {
                string newWord = word; // 用一个新单词替换word，因为每次置换一个字母
                for (int j = 0; j < 26; j++)
                {
                    newWord[i] = j + 'a'; // 'a' - 'z'
                    if (newWord == endWord)
                        return path + 1; // 找到了end，返回path+1
                    
                    // wordSet出现了newWord，并且newWord没有被访问过
                    if (wordSet.find(newWord) != wordSet.end() && visitMap.find(newWord) == visitMap.end())
                    {
                        // 添加访问信息
                        visitMap.insert(pair<string, int>(newWord, path + 1));
                        que.push(newWord);
                    }
                }
            }
        }
        return 0;
    }
};
/* 然后就是求起点和终点的最短路径长度，这里无向图求最短路，广搜最为合适，
广搜只要搜到了终点，那么一定是最短的路径。因为广搜就是以起点中心向四周扩散的搜索。

本题如果用深搜，会非常麻烦。

另外需要有一个注意点：

本题是一个无向图，需要用标记位，标记着节点是否走过，否则就会死循环！
本题给出集合是数组型的，可以转成set结构，查找更快一些
 */
// @lc code=end
