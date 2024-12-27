/*
 * @lc app=leetcode.cn id=985 lang=cpp
 *
 * [985] 查询后的偶数和
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &A, vector<vector<int>> &queries)
    {
        vector<int> res(queries.size());
        int sum = 0;

        for (int a : A)
            if (a % 2 == 0)
                sum += a;

        for (int i = 0; i < queries.size(); i++)
        {
            int val = queries[i][0];
            int index = queries[i][1];
            if ((A[index] & 1) == 1)
            { //A[index]是奇数
                if ((val & 1) == 1)
                { // val是奇数
                    sum += (A[index] + val);
                }
            }
            else
            { //A[index]是偶数
                if ((val & 1) == 0)
                { // val是偶数
                    sum += val;
                }
                else
                {
                    sum -= A[index];
                }
            }
            A[index] += val;
            res[i] = sum;
        }
        return res;
    }
};
// @lc code=end
