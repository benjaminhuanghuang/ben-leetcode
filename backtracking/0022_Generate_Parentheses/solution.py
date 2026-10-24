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
