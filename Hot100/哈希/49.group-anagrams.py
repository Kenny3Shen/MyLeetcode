#
# @lc app=leetcode.cn id=49 lang=python3
# @lcpr version=30204
#
# [49] 字母异位词分组
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        m = defaultdict(list)
        for s in strs:
            ss = ''.join(sorted(s))
            m[ss].append(s)
        return list(m.values())
# @lc code=end



#
# @lcpr case=start
# ["eat", "tea", "tan", "ate", "nat", "bat"]\n
# @lcpr case=end

# @lcpr case=start
# [""]\n
# @lcpr case=end

# @lcpr case=start
# ["a"]\n
# @lcpr case=end

#

