/*
 * @lc app=leetcode.cn id=901 lang=rust
 *
 * [901] 股票价格跨度
 *
 * https://leetcode.cn/problems/online-stock-span/description/
 *
 * algorithms
 * Medium (62.18%)
 * Likes:    396
 * Dislikes: 0
 * Total Accepted:    75.4K
 * Total Submissions: 118.6K
 * Testcase Example:  '["StockSpanner","next","next","next","next","next","next","next"]\n' +
  '[[],[100],[80],[60],[70],[60],[75],[85]]'
 *
 * 设计一个算法收集某些股票的每日报价，并返回该股票当日价格的 跨度 。
 * 
 * 当日股票价格的 跨度 被定义为股票价格小于或等于今天价格的最大连续日数（从今天开始往回数，包括今天）。
 * 
 * 
 * 
 * 例如，如果未来 7 天股票的价格是 [100,80,60,70,60,75,85]，那么股票跨度将是 [1,1,1,2,1,4,6] 。
 * 
 * 
 * 
 * 实现 StockSpanner 类：
 * 
 * 
 * StockSpanner() 初始化类对象。
 * int next(int price) 给出今天的股价 price ，返回该股票当日价格的 跨度 。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：
 * ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
 * [[], [100], [80], [60], [70], [60], [75], [85]]
 * 输出：
 * [null, 1, 1, 1, 2, 1, 4, 6]
 * 
 * 解释：
 * StockSpanner stockSpanner = new StockSpanner();
 * stockSpanner.next(100); // 返回 1
 * stockSpanner.next(80);  // 返回 1
 * stockSpanner.next(60);  // 返回 1
 * stockSpanner.next(70);  // 返回 2
 * stockSpanner.next(60);  // 返回 1
 * stockSpanner.next(75);  // 返回 4 ，因为截至今天的最后 4 个股价 (包括今天的股价 75) 都小于或等于今天的股价。
 * stockSpanner.next(85);  // 返回 6
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= price <= 10^5
 * 最多调用 next 方法 10^4 次
 * 
 * 
 */

// @lc code=start
struct StockSpanner {
    stack: Vec<(i32, i32)>,
    cur_day: i32,
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl StockSpanner {

    fn new() -> Self {
        StockSpanner { 
            stack: vec![(-1, i32::MAX)],  // (day, price) 保持 stack 不为空
            cur_day: -1  
        }
    }
    
    fn next(&mut self, price: i32) -> i32 {
        while price >= self.stack.last().unwrap().1 {
            self.stack.pop();
        }
        self.cur_day += 1;
        let res = self.cur_day - self.stack.last().unwrap().0;
        self.stack.push((self.cur_day, price));
        res
    }
}

// @lc code=end

