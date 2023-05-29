/*
 * @lc app=leetcode.cn id=705 lang=cpp
 *
 * [705] 设计哈希集合
 *
 * https://leetcode-cn.com/problems/design-hashset/description/
 *
 * algorithms
 * Easy (58.68%)
 * Likes:    88
 * Dislikes: 0
 * Total Accepted:    24K
 * Total Submissions: 40.9K
 * Testcase Example:  '["MyHashSet","add","add","contains","contains","add","contains","remove","contains"]\n' +
  '[[],[1],[2],[1],[3],[2],[2],[2],[2]]'
 *
 * 不使用任何内建的哈希表库设计一个哈希集合（HashSet）。
 * 
 * 实现 MyHashSet 类：
 * 
 * 
 * void add(key) 向哈希集合中插入值 key 。
 * bool contains(key) 返回哈希集合中是否存在这个值 key 。
 * void remove(key) 将给定值 key 从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：
 * ["MyHashSet", "add", "add", "contains", "contains", "add", "contains",
 * "remove", "contains"]
 * [[], [1], [2], [1], [3], [2], [2], [2], [2]]
 * 输出：
 * [null, null, null, true, false, null, true, null, false]
 * 
 * 解释：
 * MyHashSet myHashSet = new MyHashSet();
 * myHashSet.add(1);      // set = [1]
 * myHashSet.add(2);      // set = [1, 2]
 * myHashSet.contains(1); // 返回 True
 * myHashSet.contains(3); // 返回 False ，（未找到）
 * myHashSet.add(2);      // set = [1, 2]
 * myHashSet.contains(2); // 返回 True
 * myHashSet.remove(2);   // set = [1]
 * myHashSet.contains(2); // 返回 False ，（已移除）
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * 最多调用 10^4 次 add、remove 和 contains 。
 * 
 * 
 * 
 * 
 * 进阶：你可以不使用内建的哈希集合库解决此问题吗？
 * 
 */
#include "leetcode.h"
// @lc code=start
class MyHashSet
{
private:
    constexpr static int maxSize = 10009;
    vector<list<int>> v;

    int GetIndex(int x)
    {
        return x % maxSize;
    }

public:
    /** Initialize your data structure here. */
    MyHashSet() : v(maxSize)
    {
    }

    void add(int key)
    {
        int i = GetIndex(key);
        for (auto iter = v[i].begin(); iter != v[i].end(); ++iter)
        {
            // 已存在则直接忽略
            if ((*iter) == key)
            {
                return;
            }
        }
        v[i].push_back(key);
    }

    void remove(int key)
    {
        int i = GetIndex(key);
        for (auto iter = v[i].begin(); iter != v[i].end(); ++iter)
        {
            if ((*iter) == key)
            {
                // 删除存在的结点
                v[i].erase(iter--); //迭代器失效
                //return;
            }
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        int i = GetIndex(key);
        for (auto iter = v[i].begin(); iter != v[i].end(); ++iter)
        {
            // 找到则返回
            if ((*iter) == key)
            {
                return true;
            }
        }
        return false;
    }
};
/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end
