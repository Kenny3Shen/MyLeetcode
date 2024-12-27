/*
 * @lc app=leetcode.cn id=976 lang=cpp
 *
 * [976] 三角形的最大周长
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int largestPerimeter(vector<int> &arr)
    {
        sort(arr.rbegin(), arr.rend());
        for(int i = 0; i + 2 < arr.size(); i++)
            if(arr[i] < arr[i + 1] + arr[i + 2])
                return arr[i] + arr[i + 1] + arr[i + 2];
        // arr[i] >= arr[i + 1] + arr[i + 2] 则选次小的三边
        return 0;
    }
};
// @lc code=end
