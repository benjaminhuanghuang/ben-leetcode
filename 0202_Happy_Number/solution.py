'''
202. Happy Number

Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process:
    Starting with any positive integer, replace the number by the sum of the squares of its digits,
    and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in
    a cycle which does not include 1.

    Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1

'''


def is_happy_num(n):
    numSet = set()
    while True:
        numSet.add(n)
        n = sum([int(x) * int(x) for x in str(n)])
        if n == 1 or n in numSet:
            break
    return n == 1


def isHappy(n):
    numSet = set()
    while n != 1 and n not in numSet:
        numSet.add(n)
        sum = 0
        while n:
            digit = n % 10
            sum += digit * digit
            n /= 10
        n = sum
    return n == 1


print is_happy_num(1111111)
