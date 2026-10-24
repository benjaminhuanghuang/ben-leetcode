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
