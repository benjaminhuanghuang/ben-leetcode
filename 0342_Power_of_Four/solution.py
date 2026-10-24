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
