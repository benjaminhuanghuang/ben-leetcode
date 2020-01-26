'''
405. Convert a Number to Hexadecimal

Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two's complement method is used.

Note:

All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single
zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed integer.
You must not use any method provided by the library which converts/formats the number to hex directly.
Example 1:

Input:
26

Output:
"1a"
Example 2:

Input:
-1

Output:
"ffffffff"
'''


class Solution(object):
    def toHex_good(self, num):
        """
        :type num: int
        :rtype: str
        """
        ans = []
        hexs = '0123456789abcdef'
        if num < 0:
            num += 0x100000000  # Two's complement
        while num:
            ans.append(hexs[num % 16])
            num /= 16
        return ''.join(ans[::-1]) if ans else '0'

    def toHex_my(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num >= 0:
            res = self.convert_positive_to_hex(num)
        else:
            complement = self.get_complement(num)
            res = self.convert_positive_to_hex(complement)
        return res

    def get_complement(self, num):
        num = -num
        complement = ~num + 1
        complement = (2 ** 32 - 1) & complement
        return complement

    def convert_positive_to_hex(self, num):
        result = ""
        while num:
            digit = num % 16
            result = self.convert_digit_to_hex(digit) + result
            num = num / 16
        return result

    def convert_digit_to_hex(self, digit):
        hex_digital = ["a", "b", "c", "d", "e", "f"]
        if digit < 10:
            return str(digit)
        else:
            return hex_digital[digit - 10]


input = 0
s = Solution()
print s.toHex(input)
