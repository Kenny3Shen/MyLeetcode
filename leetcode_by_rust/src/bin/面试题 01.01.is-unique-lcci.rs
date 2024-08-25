/*
 * @lc app=leetcode.cn id= 面试题 01.01 lang=rust
 * @lcpr version=30204
 *
 * [ 面试题 01.01] 判定字符是否唯一
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn is_unique(astr: String) -> bool {
        // let mut map = std::collections::HashMap::new();
        // for c in astr.chars() {
        //     match map.get(&c) {
        //         Some(_) => return false,
        //         None => {
        //             map.insert(c, 1);
        //         }
        //     }
        // }
        // true
        
        // 基于位运算的解法
        // 基本思路：使用一个整数来表示 26 个字母，每一位表示一个字母是否出现过
        // 1. 遍历字符串，对于每一个字符，计算其相对于 'a' 的偏移量
        // 2. 将 1 左移偏移量位，与 mark 进行或运算
        // 3. 如果 mark 中已经有了该字符，则返回 false
        // 4. 否则，将 mark 中对应的位置 1
        // 5. 遍历结束，返回 true
        let mut mark = 0;
        for c in astr.chars() {
            let shift = c as i32 - 'a' as i32;
            if (mark & (1 << shift)) != 0 {
                return false;
            }
            mark |= 1 << shift;
        }
        true
    }
}
// @lc code=end



/*
// @lcpr case=start
// "leetcode"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n
// @lcpr case=end

 */

