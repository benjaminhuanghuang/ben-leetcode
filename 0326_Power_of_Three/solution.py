'''
326. Power of Three

Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion?

'''

import math

# Naive version
def is_power_of_3(n):
    if n <= 0:
        return False
    if n == 1:
        return True

    while (n > 1):
        if n % 3 != 0:
            return False
        n = n / 3

    return True

# Naive version 2
def is_power_of_3_recursion(n):
    """
    :type n: int
    :rtype: bool
    """
    if n <= 0:
        return False
    if n == 1:
        return True
    return n % 3 == 0 and is_power_of_3_recursion(n / 3)


# http://my.oschina.net/Tsybius2014/blog/601048
# def is_power_of_3_2(n):
#     if n <= 0:
#         return False
#     if n == 1:
#         return True
#
#     return Integer.toString(n, 3).matches("10*");

def is_power_of_3_log(n):
    return False if n <= 0 else n == round(3 ** round(math.log(n, 3)))