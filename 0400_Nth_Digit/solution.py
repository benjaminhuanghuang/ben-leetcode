'''
400. Nth Digit

Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 2^31).

Example 1:

Input:
3

Output:
3
Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
'''


class Solution(object):
    # http://bookshadow.com/weblog/2016/09/18/leetcode-nth-digit/
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        for i in range(9):
            d = 9 * 10 ** i
            if n <= d * (i + 1):
                break
            n -= d * (i + 1)
        n -= 1
        print "d * (i+1) ", d * (i + 1)
        print "i ", i
        print "n ", n
        print "d ", d

        print str(10 ** i + n / (i + 1))
        return int(str(10 ** i + n / (i + 1))[n % (i + 1)])

    def n_digits_num(self):
        i = 1
        while True:
            num = 10 ** (i - 1) - 1
            if num > 2 ** 31:
                break
            digit_count = 9 * (10 ** (i - 1)) * i

            print "There a {} digits come with {}-digits numbers ".format(digit_count, i)
            i += 1

    def findNthDigit_2(self, n):
        # how many digits come with i-digits number
        arr = [0, 9, 189, 2889, 38889, 488889, 5888889, 68888889, 788888889]
        digits = 0  # how many digits the number n has
        while True:
            if (digits > 8) or (arr[digits] > n):
                break
            digits += 1
        print digits

        t = n - arr[digits - 1] - 1  # location in the section
        num = (t / digits) + (10 ** (digits - 1))  # the number has n-th digit
        p = digits - (t % digits) - 1  # the digit of the number
        for i in xrange(p):
            num /= 10
        return num % 10

    #  1 - 9   : 9
    #  10 - 99 : (99 - 10 + 1) *2 = 90 *2
    #  100 - 999 :  (999 - 100 + 1) * 3 = 900 * 3
    #                                   =  count * len
    def findNthDigit(self, n):
        start = 1  # the first number in the range
        len = 1
        count = 9  # 1-9
        while n > len * count:
            n = n - len * count
            len += 1
            count = count * 10
            start = start * 10

        number = start + (n - 1) / len
        s = str(number)
        return int(s[(n - 1) % len])


n = 12
s = Solution()
# s.n_digits_num()
# print 2 ** 31
# print s.findNthDigit(n)
print s.findNthDigit_2(n)
