/*
 * @lc app=leetcode.cn id=825 lang=cpp
 *
 * [825] 适龄的朋友
 *
 * https://leetcode-cn.com/problems/friends-of-appropriate-ages/description/
 *
 * algorithms
 * Medium (37.61%)
 * Likes:    56
 * Dislikes: 0
 * Total Accepted:    5.1K
 * Total Submissions: 13.4K
 * Testcase Example:  '[16,16]'
 *
 * 人们会互相发送好友请求，现在给定一个包含有他们年龄的数组，ages[i] 表示第 i 个人的年龄。
 * 
 * 当满足以下任一条件时，A 不能给 B（A、B不为同一人）发送好友请求：
 * 
 * 
 * age[B] 
 * age[B] > age[A]
 * age[B] > 100 && age[A] < 100
 * 
 * 
 * 否则，A 可以给 B 发送好友请求。
 * 
 * 注意如果 A 向 B 发出了请求，不等于 B 也一定会向 A 发出请求。而且，人们不会给自己发送好友请求。 
 * 
 * 求总共会发出多少份好友请求?
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：[16,16]
 * 输出：2
 * 解释：二人可以互发好友申请。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：[16,17,18]
 * 输出：2
 * 解释：好友请求可产生于 17 -> 16, 18 -> 17.
 * 
 * 示例 3：
 * 
 * 
 * 输入：[20,30,100,110,120]
 * 输出：3
 * 解释：好友请求可产生于 110 -> 100, 120 -> 110, 120 -> 100.
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {

    }
};
// @lc code=end

