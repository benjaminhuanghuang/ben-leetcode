'''
371. Sum of Two Integers

Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.


https://www.hrwhisper.me/leetcode-sum-two-integers/

http://bookshadow.com/weblog/2016/06/30/leetcode-sum-of-two-integers/
Python will convert int to long int when the left-shift result too big
In python did not have limitation for the long int
'''

'''
// use a ^ b can calculate sum without carry
// use (a & b) << 1 can calculate carry

//  C solution 1
int getSum(int a, int b) {
    if (b == 0) return a;
    int sum = a ^ b;
    int carry = (a & b) << 1;
    return getSum(sum, carry);
}

//  C solution 2
int getSum(int a, int b) {
    while (b) {
        int carry = (a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}
'''


def get_sum(a, b):
    """
    :type a: int
    :type b: int
    :rtype: int
    """
    MAX_INT = 0x7FFFFFFF
    MASK = 0xFFFFFFFF
    while b:
        a, b = (a ^ b) & MASK, ((a & b) << 1) & MASK

    # if a > MAX_INT means it is a negative number
    # a & MAX_INT  cut 32 bits, but sign bit was changed to 0
    # ~(a & MAX_INT)  change single bit(s) to 1, but inverse all rest bits
    # ~(a & MAX_INT) ^ MAX_INT inverse all rest bits, because all bits in MAX_INT are 1s,  1^0 =1, 1^1=0
    return a if a <= MAX_INT else ~(a & MAX_INT) ^ MAX_INT


# Cause infinite loop, because Python will convert int to long int when the left-shift result too big
# can not pass (-1,1)
def get_sum_c(a, b):
    # b is carry , a is bit sum
    while b:
        print b
        print "\n"
        a, b = (a ^ b), (a & b) << 1
    return a


# Wrong solution
def get_sum_my(a, b):
    MAX_INT = 0x7FFFFFFF
    MASK = 0xFFFFFFFF
    while b:
        a, b = (a ^ b) & MASK, ((a & b) << 1) & MASK
    #  0xFFFFFFFF80000000 will change data to long
    return a if a <= MAX_INT else ((a & MAX_INT) | 0xFFFFFFFF80000000)


print get_sum_my(-1, 1)

# 0xFFFFFFFF80000000
# 0x7FFFFFFFFFFFFFFF
#
import sys

print "Biggest int"
print sys.maxint
print bin(9223372036854775807)
print hex(9223372036854775807)
print -sys.maxint - 10
print bin(-sys.maxint - 1)

print bin(-2)
print bin(-2 & 0x7fffffff)
print bin(2147483646)
print bin(-2147483646)
print bin(18446744073709551614)

print type(0x7FFFFFFFFFFFFFFF)
print type(0xFFFFFFFFFFFFFFFF)

#
# print "-- test --"
print get_sum_my(-1, 1)
print get_sum_my(2, 1)
print get_sum_my(-1, -1)

print type(18446744073709551614)
