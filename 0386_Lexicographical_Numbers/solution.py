'''
386. Lexicographical Numbers

Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.

'''


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
