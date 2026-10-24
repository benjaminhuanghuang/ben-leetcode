class Solution(object):
    def lexicalOrder(self, n):
        """
        :type n: int
        :rtype: List[int]
        """

        if n < 1:
            return []

        res = []
        # first bit are 1 to 9
        for first_digit in xrange(1, 10):
            if first_digit > n:
                break
            res.append(first_digit)
            self.get_all_number(first_digit, n, res)
        return res

    def get_all_number(self, existed_digits, n, res):
        for digit in xrange(10):
            number = existed_digits * 10 + digit
            if number <= n:
                res.append(number)
                self.get_all_number(number, n, res)
            else:
                break


s = Solution()
print s.lexicalOrder(5201)
