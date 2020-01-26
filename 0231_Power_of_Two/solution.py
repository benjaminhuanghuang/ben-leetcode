'''
231. Power of Two

Given an integer, write a function to determine if it is a power of two.

'''


# http://www.cnblogs.com/grandyang/p/4623394.html
# The power of 2 only have one "1" ant most left bit
def is_power_of_2(n):
    count_of_1 = 0
    while (n > 0):
        count_of_1 += (n & 1)
        n >>= 1

    return count_of_1 == 1


# The power of 2 only have one "1" ant most left bit
# if minus 1 from it, all of bits in the result will be 1
def is_power_of_2_2(n):
    return (n > 0) and (not (n & (n - 1)))
