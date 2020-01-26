'''
258. Add Digits

Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

A naive implementation of the above process is trivial :-)

http://www.cnblogs.com/grandyang/p/4741028.html
'''


# naive implementation
def sum_digits(n):
    result = 0
    while n / 10 > 0:
        result += n % 10
        n = n / 10
    result += n
    return result


def add_digits(n):
    sum = sum_digits(n)
    while sum / 10 > 0:
        sum = sum_digits(sum)
    return sum


# Final solution
def addDigits(num):
    if num == 0:
        # -1 % 9 = 8
        return 0
    return (num - 1) % 9 + 1


print add_digits(38)

print addDigits(0)
