'''
357. Count numbers with unique digits

Given a non-negative integer n, count all numbers with unique digits, x, where 0 <= x < 10^n.

Example:
Given n = 2, return 91.
The answer should be the total numbers in the range of 0 <= x < 100, excluding [11,22,33,44,55,66,77,88,99])

The answer should be
0, 1
1, 10
2, 91
3, 739
4, 5275
5, 32491
6, 168571
7, 712891
8, 2345851
9, 5611771
10 and beyond, 8877691

Reference:
    http://www.cnblogs.com/grandyang/p/5582633.html
    https://leetcode.com/discuss/107981/backtracking-solution

'''

from utilities.decorators import *


def count_numbers_with_unique_digits_combinatorics(n):
    """
    This problem can also be solved using a dynamic programming approach and some knowledge of combinatorics.
        count of 1 bit number  10
        count of 2 bits number is 9*9
        count of 3 bits number is 9*9*8
        count of n bit s number is 9 * 9 * 8 * ....(9- n +2 )
    :param n: the bits of the number
    :return:
    """
    if n == 0:
        return 1

    res = 10  # 10 numbers for 1 bit
    count = 9

    for i in xrange(2, n + 1):
        count *= (11 - i)
        res += count

    return res


def count_numbers_with_unique_digits_backtracking(n):
    '''
    Backtracking should contains three states which are
        - the current number,
        - number of steps to get that number
        - a bitmask which represent which number is marked as visited so far in the current number

    Start with state (0,0,0) and count all valid number till we reach number of steps equals to 10^n.

    The idea is to append one digit at a time recursively (only append digits that has not been appended before).
    if n = 1, the number can be 1 to 9
    if n = 2, the number can be (the number of step 1 * 10) + (0 to 9 exclude the digit used in step 1 )
    ...
    :param n:
    :return:
    '''
    count = 1
    max = 10 ** n
    used = 0   # bit i = 1 means digit i was used
    # another implementation : boolean[] used = new boolean[10];

    for i in range(1, 10):   # number can not leading with zero
        used |= (1 << i)
        count += search(i, max, used)
        used &= ~(1 << i)

    return count


def search(pre, max, used):
    count = 0
    if pre < max:
        count += 1
    else:
        return count

    for i in range(0, 10):
        if not (used & (1 << i)):
            used |= (1 << i)
            cur = 10 * pre + i
            count += search(cur, max, used)
            used &= ~(1 << i)
    return count
