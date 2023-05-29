/*
 * @lc app=leetcode.cn id=721 lang=rust
 *
 * [721] 账户合并
 *
 * https://leetcode.cn/problems/accounts-merge/description/
 *
 * algorithms
 * Medium (48.15%)
 * Likes:    435
 * Dislikes: 0
 * Total Accepted:    39.1K
 * Total Submissions: 81.2K
 * Testcase Example:  '[["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]'
 *
 * 给定一个列表 accounts，每个元素 accounts[i] 是一个字符串列表，其中第一个元素 accounts[i][0] 是 名称
 * (name)，其余元素是 emails 表示该账户的邮箱地址。
 *
 *
 * 现在，我们想合并这些账户。如果两个账户都有一些共同的邮箱地址，则两个账户必定属于同一个人。请注意，即使两个账户具有相同的名称，它们也可能属于不同的人，因为人们可能具有相同的名称。一个人最初可以拥有任意数量的账户，但其所有账户都具有相同的名称。
 *
 * 合并账户后，按以下格式返回账户：每个账户的第一个元素是名称，其余元素是 按字符 ASCII 顺序排列 的邮箱地址。账户本身可以以 任意顺序
 * 返回。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John",
 * "johnnybravo@mail.com"], ["John", "johnsmith@mail.com",
 * "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
 * 输出：[["John", 'john00@mail.com', 'john_newyork@mail.com',
 * 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary",
 * "mary@mail.com"]]
 * 解释：
 * 第一个和第三个 John 是同一个人，因为他们有共同的邮箱地址 "johnsmith@mail.com"。
 * 第二个 John 和 Mary 是不同的人，因为他们的邮箱地址没有被其他帐户使用。
 * 可以以任何顺序返回这些列表，例如答案
 * [['Mary'，'mary@mail.com']，['John'，'johnnybravo@mail.com']，
 * ['John'，'john00@mail.com'，'john_newyork@mail.com'，'johnsmith@mail.com']]
 * 也是正确的。
 *
 *
 * 示例 2：
 *
 *
 * 输入：accounts =
 * [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
 *
 * 输出：[["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= accounts.length <= 1000
 * 2 <= accounts[i].length <= 10
 * 1 <= accounts[i][j].length <= 30
 * accounts[i][0] 由英文字母组成
 * accounts[i][j] (for j > 0) 是有效的邮箱地址
 *
 *
 */

// @lc code=start
use std::collections::HashMap;
struct UnionFind {
    parent: Vec<usize>,
    rank: Vec<usize>,
}
impl UnionFind {
    fn new(n: usize) -> Self {
        UnionFind {
            parent: (0..n).collect(),
            rank: vec![0; n],
        }
    }

    fn find(&mut self, x: usize) -> usize {
        if self.parent[x] != x {
            self.parent[x] = self.find(self.parent[x]);
        }
        self.parent[x]
    }

    fn union(&mut self, x: usize, y: usize) {
        let x_root = self.find(x);
        let y_root = self.find(y);
        if self.rank[x_root] >= self.rank[y_root] {
            self.parent[y_root] = x_root;
        } else {
            self.parent[x_root] = y_root;
        }
        if self.rank[x_root] == self.rank[y_root] {
            self.rank[x_root] += 1;
        }
    }
}
impl Solution {
    pub fn accounts_merge(accounts: Vec<Vec<String>>) -> Vec<Vec<String>> {
        let n = accounts.len();
        let mut uf: UnionFind = UnionFind::new(n);
        let mut res: Vec<Vec<String>> = Vec::new();
        let mut email_to_id: HashMap<String, usize> = HashMap::new();
        for i in 0..n {
            for email in accounts[i].iter().skip(1) {
                let t = email_to_id.entry(email.clone()).or_insert(i); //bind email to account_id
                uf.union(i, *t); //the accounts[i] point to the same parent (account_id)
            }
        }

        let mut id_to_email: HashMap<usize, Vec<String>> = HashMap::new();
        for (k, v) in email_to_id.iter_mut() {
            let account_id = uf.find(*v); //find the parent of this email
            let t = id_to_email.entry(account_id).or_insert(Vec::new());
            t.push(k.clone()); // add email for this parent
        }

        for (k, v) in id_to_email.iter_mut() {
            v.sort_unstable(); // sort by ascii order
            v.insert(0, accounts[*k][0].clone());
            res.push(v.to_vec());
        }

        res
    }
}
// @lc code=end
