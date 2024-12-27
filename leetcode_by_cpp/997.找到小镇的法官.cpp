/*
 * @lc app=leetcode.cn id=997 lang=cpp
 *
 * [997] 找到小镇的法官
 *
 * https://leetcode-cn.com/problems/find-the-town-judge/description/
 *
 * algorithms
 * Easy (51.19%)
 * Likes:    90
 * Dislikes: 0
 * Total Accepted:    22.7K
 * Total Submissions: 44.2K
 * Testcase Example:  '2\n[[1,2]]'
 *
 * 在一个小镇里，按从 1 到 N 标记了 N 个人。传言称，这些人中有一个是小镇上的秘密法官。
 * 
 * 如果小镇的法官真的存在，那么：
 * 
 * 
 * 小镇的法官不相信任何人。
 * 每个人（除了小镇法官外）都信任小镇的法官。
 * 只有一个人同时满足属性 1 和属性 2 。
 * 
 * 
 * 给定数组 trust，该数组由信任对 trust[i] = [a, b] 组成，表示标记为 a 的人信任标记为 b 的人。
 * 
 * 如果小镇存在秘密法官并且可以确定他的身份，请返回该法官的标记。否则，返回 -1。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：N = 2, trust = [[1,2]]
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 输入：N = 3, trust = [[1,3],[2,3]]
 * 输出：3
 * 
 * 
 * 示例 3：
 * 
 * 输入：N = 3, trust = [[1,3],[2,3],[3,1]]
 * 输出：-1
 * 
 * 
 * 示例 4：
 * 
 * 输入：N = 3, trust = [[1,2],[2,3]]
 * 输出：-1
 * 
 * 
 * 示例 5：
 * 
 * 输入：N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
 * 输出：3
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= N <= 1000
 * trust.length <= 10000
 * trust[i] 是完全不同的
 * trust[i][0] != trust[i][1]
 * 1 <= trust[i][0], trust[i][1] <= N
 * 
 * 
 */
#include <vector>
#include <memory.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findJudge(int N, vector<vector<int>> &trust)
    {
        /* if (trust.empty())
            return N == 1 ? 1 : -1;

        bool AtrustJudge[N + 1]; //除了这个 B ,其余A都要相信 B
        for (int i = 0; i < trust.size(); i++)
        {
            int curB = trust[i][1]; //假定这个 B是法官
            //vector<bool> AtrustJudge(N + 1, false); //除了这个 B 其余A都要相信 B
            memset(AtrustJudge, false, sizeof(AtrustJudge)); //initialize
            AtrustJudge[trust[i][0]] = true;                 //这个 B要跳过判断
            bool isJudge = true;
            bool maybeJudge = true;
            for (int j = 0; j < trust.size(); j++)
            {
                if (i == j)
                    continue;
                if (trust[j][0] == curB) //这个 B要是法官就不会出现在 A中
                {
                    isJudge = false;
                    maybeJudge = false;
                    break;
                }
                else
                {
                    if (trust[j][1] == curB)
                        AtrustJudge[trust[j][0]] = true; // A( A != B)相信这个 B
                }
            }
            if (maybeJudge) //这个 B 可能是法官，还要判断其余 A是否都相信这个 B
            {
                for (int k = 1; k <= N; k++)
                {
                    if (k == curB)
                        continue;
                    if (AtrustJudge[k] == false) //有人不相信这个 B
                    {
                        isJudge = false;
                        break;
                    }
                }
            }
            if (isJudge)
                return curB;
        }
        return -1; */

        vector<int> count(N + 1, 0); // 1-N 每个的获得的票数
        for (const auto &t : trust)
        {
            count[t[1]]++; // B 被投一票
            count[t[0]]--; // A 投一票别人
        }

        for (int i = 1; i <= N; i++)
        {
            if (count[i] == N - 1) //法官只能被投票而不能投别人票
                return i;          //则法官的票数一定为 N - 1
        }

        return -1;
    }
};
// @lc code=end
