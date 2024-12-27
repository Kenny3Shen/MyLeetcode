/*
 * @lc app=leetcode.cn id=767 lang=cpp
 *
 * [767] 重构字符串
 */
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string reorganizeString(string S)
    {
        unordered_map<char, int> map;
        int maxFrequency = 0;
        for (auto const &c : S)
        {
            map[c]++;
            maxFrequency = max(maxFrequency, map[c]); //出现次数最多字符
        }
        if (maxFrequency * 2 - 1 > S.length()) //至少有两个相同的字符连在一起
            return "";
        vector<pair<char, int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), [&](auto const &a, auto const &b) {
            return a.second > b.second;
        });
        int insertIndex = 0; // 0 2 4 6.....
        for (int i = 0; i < vec.size(); i++)
        {
            while (vec[i].second--) //剩余使用次数
            {
                S[insertIndex] = vec[i].first;
                insertIndex += 2;              //先按奇数位插入(Index = 0,2,4,6...)
                if (insertIndex >= S.length()) //if 应放入 while循环中放置越界
                    insertIndex = 1;           //再按偶数位插入(Index = 1,3,5...)
            }
        }
        return S;
    }
};
/* 
1.用map统计频率字符频率
2.转为vector（即数组）按频率从大到小排序
3.按奇数位顺序插入，插满之后按偶数位顺序插入
为什么要先按奇数位插入(Index = 0,2,4,6,8...)呢？
先按奇数位插入，保证最大的字符分散开，因为奇数位总是>=偶数位！
 */
// @lc code=end
