/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        //在 flowerbed数组两端各增加一个 0,不用考虑边界条件，任意位置处只要连续出现三个 0 就可以栽上一棵花。
        /* flowerbed.push_back(0);
        flowerbed.insert(flowerbed.begin(), 0);
        for (int i = 1; i < flowerbed.size() - 1; i++)
        {
            if (!flowerbed[i - 1] && !flowerbed[i] && !flowerbed[i + 1])
            {
                flowerbed[i] = 1;
                n--;
            }
        }
        return n <= 0; */

        for (int i = 0; i < flowerbed.size(); i++)
        {
            if (n <= 0)
            { // 如果已经种够花了，可以提前返回true
                return true;
            }
            if (flowerbed[i] == 1)
            { // 如果已经种过花了，则不能再种了
                continue;
            }
            if (i > 0 && flowerbed[i - 1] == 1)
            { // 如果上一个格子已经种过花了，则当前这格不能种花
                continue;
            }
            if (i < flowerbed.size() - 1 && flowerbed[i + 1] == 1)
            { // 如果下一个格子已经种过花了，则当前这格不能种花
                continue;
            }
            // 可以种花了，并且记录次数
            flowerbed[i] = 1;
            n--;
        }
        return n <= 0;
    }
};
// @lc code=end
