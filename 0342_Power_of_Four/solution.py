'''
342. Power of Four

Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?
'''


def is_power_of_four(num):
    """
    :type num: int
    :rtype: bool
    """
    # power of 2 : 10000.. num & (num - 1)
    # power of 4 : 1, 100, 10000, 1000000, num = .....0x55555555 = ...01010101, Note: 5 &0x55555555 !=0
    return num > 0 and num & (num - 1) == 0 and num & 0x55555555 != 0


# return num > 0 and num & (num - 1) == 0 and num & 0x55555555 !=

print is_power_of_four(5)
