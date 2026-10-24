'''
9. Palindrome Number
Determine whether an integer is a palindrome. "Do this without extra space".
'''


class Solution(object):
    def isPalindrome_1(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False

        tmp = x
        re = 0
        while tmp > 0:
            re = re * 10 + tmp % 10
            tmp = tmp / 10

        return re == x

    def isPalindrome_2(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False

        len = 1
        tmp = x
        while tmp / 10 > 0:
            len += 1
            tmp = tmp / 10

        if len == 1:
            return True

        start = 0
        end = len - 1
        while start < end:
            #
            if x % (10 ** (len - end)) / (10 ** (len - end - 1)) != \
                                    x % (10 ** (len - start)) / (10 ** (len - start - 1)):
                return False
            else:
                start += 1
                end -= 1

        return True


s = Solution()

# print s.isPalindrome_2(121)
print s.isPalindrome_2(1001)
