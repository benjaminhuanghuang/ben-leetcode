'''
22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

Algorithm:
Keep track of counts of open and close brackets. Initialize these counts as 0.
Recursively call the printParenthesis() function until open bracket count is less than the given n.

If open bracket count becomes more than the close bracket count, then put a closing bracket and
recursively call for the remaining brackets.

If open bracket count is less than n, then put an opening bracket and call printParenthesis()
for the remaining brackets.
'''


class Solution(object):
    def generate_parenthesis_wrong(self, n):
        if n == 0:
            return []
        res = []
        self.helpler2(n, n, '', res)

        return res

    def helpler(self, l, r, item, res):     # Wrong!
        if l == 0 and r == 0:
            res.append(item)
        if l > 0:
            self.helpler(l - 1, r, item + '(', res)
        if r > 0:   # Wrong, generate )))(((
            self.helpler(l, r - 1, item + ')', res)

    def helpler_2(self, l, r, item, res):
        if l == 0 and r == 0:
            res.append(item)
            return
        if l > 0:
            self.helpler(l - 1, r, item + '(', res)
        if r > l:
            self.helpler(l, r - 1, item + ')', res)

    # https://miafish.wordpress.com/2014/12/23/get-all-combinations-of-balanced-parentheses/
    # https://discuss.leetcode.com/topic/3474/an-iterative-method
    def genterte_parentheses_iteration(self, n):
        if n == 0:
            return []
        res = [['']]
        for i in xrange(n + 1):
            res.append([])
            for j in xrange(i):
                # pick first one and last one  left->      <-right
                left = res[j]
                right = res[i - j - 1]
                for front in left:
                    for back in right:
                        res[i].append('(' + front + ')' + back)
        return res[n]


s = Solution()
# print s.genterte_parentheses_iteration(4)
print s.generate_parenthesis_wrong(3)
