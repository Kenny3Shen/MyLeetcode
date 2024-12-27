/*
 * @lc app=leetcode.cn id=313 lang=cpp
 *
 * [313] 超级丑数
 */
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        priority_queue<long long, vector<long long>, greater<long long>> buff;
        unordered_set<long long> primeset;

        buff.push(1);
        primeset.insert(1);
        long long i = 1;
        int count = 0;
        while (count < n)
        {
            count++;
            i = buff.top();
            buff.pop();
            for (long long prime : primes)
            {
                long long next = i * prime;
                if (next <= INT32_MAX && !primeset.count(next))
                {
                    buff.push(next);
                    primeset.insert(next);
                }
            }
        }

        return i;
    }
};
// @lc code=end
