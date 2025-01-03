/*
 * @lc app=leetcode.cn id=381 lang=cpp
 *
 * [381] O(1) 时间插入、删除和获取随机元素 - 允许重复
 *
 * https://leetcode-cn.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/
 *
 * algorithms
 * Hard (38.09%)
 * Likes:    134
 * Dislikes: 0
 * Total Accepted:    9.2K
 * Total Submissions: 21.4K
 * Testcase Example:  '["RandomizedCollection","insert","insert","insert","getRandom","remove","getRandom"]\n[[],[1],[1],[2],[],[1],[]]'
 *
 * 设计一个支持在平均 时间复杂度 O(1) 下， 执行以下操作的数据结构。
 * 
 * 注意: 允许出现重复元素。
 * 
 * 
 * insert(val)：向集合中插入元素 val。
 * remove(val)：当 val 存在时，从集合中移除一个 val。
 * getRandom：从现有集合中随机获取一个元素。每个元素被返回的概率应该与其在集合中的数量呈线性相关。
 * 
 * 
 * 示例:
 * 
 * // 初始化一个空的集合。
 * RandomizedCollection collection = new RandomizedCollection();
 * 
 * // 向集合中插入 1 。返回 true 表示集合不包含 1 。
 * collection.insert(1);
 * 
 * // 向集合中插入另一个 1 。返回 false 表示集合包含 1 。集合现在包含 [1,1] 。
 * collection.insert(1);
 * 
 * // 向集合中插入 2 ，返回 true 。集合现在包含 [1,1,2] 。
 * collection.insert(2);
 * 
 * // getRandom 应当有 2/3 的概率返回 1 ，1/3 的概率返回 2 。
 * collection.getRandom();
 * 
 * // 从集合中删除 1 ，返回 true 。集合现在包含 [1,2] 。
 * collection.remove(1);
 * 
 * // getRandom 应有相同概率返回 1 和 2 。
 * collection.getRandom();
 * 
 * 
 */
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
class RandomizedCollection
{
public:
    unordered_map<int, unordered_set<int>> value_indices;
    vector<int> nums;
    /** Initialize your data structure here. */
    RandomizedCollection()
    {
    }

    /** Inserts a value to the collection. 
     * Returns true if the collection did not already contain the specified element. */
    bool insert(int val)
    {
        bool res = value_indices.count(val) == 0;
        nums.push_back(val);
        value_indices[val].insert(nums.size() - 1);
        return res;
    }

    /** Removes a value from the collection. 
     * Returns true if the collection contained the specified element. */
    bool remove(int val)
    {
        if (value_indices.count(val) == 0)
            return false;
        int tail = nums.back();
        if (tail == val)
        {
            value_indices[val].erase(nums.size() - 1);
            nums.pop_back();
        }
        else
        {
            int ind = *value_indices[val].begin();
            nums[ind] = tail;
            value_indices[tail].erase(nums.size() - 1);
            value_indices[tail].insert(ind);
            value_indices[val].erase(ind);
            nums.pop_back();
        }
        if (value_indices[val].empty())
        {
            value_indices.erase(val);
        }
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom()
    {
        int s = nums.size();
        int r = rand() % s;
        return nums[r];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
