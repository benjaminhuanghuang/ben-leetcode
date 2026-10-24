class Solution(object):
    def validUtf8(self, data):
        """
        :type data: List[int]
        :rtype: bool
        """
        #        0, 10000000, 11100000, 11110000, 11111000
        masks = [0x0, 0x80, 0xE0, 0xF0, 0xF8]
        #        0 ,  0  ,  11000000, 11100000, 11110000
        bits = [0x0, 0x0, 0xC0, 0xE0, 0xF0]
        while data:
            for i in (4, 3, 2, 1, 0):
                if data[0] & masks[i] == bits[i]:
                    break
            length = i
            if length == 0 or len(data) < length:
                return False
            for y in range(1, length):
                if data[y] & 0xC0 != 0x80:
                    return False
            data = data[length:]
        return True

    def validUtf8_wrong(self, data):
        """
        :type data: List[int]
        :rtype: bool
        """
        n = len(data)
        skip = 0b10000000
        check = 0
        for i in xrange(n):
            if check > 0:
                # first left bit is 1
                if data[i] & skip == skip:
                    check -= 1
                else:
                    return False
            else:
                check = self.get_type(data[i])
                if check < 0:
                    return False
        return check == 0

    def get_type(self, num):
        if ((num & 0b11110000) == 0b11110000): return 3
        if ((num & 0b11100000) == 0b11100000): return 2
        if ((num & 0b11000000) == 0b11000000): return 1
        if ((num & 0b10000000) == 0b10000000): return -1
        return 0


s = Solution()
# data = [197, 130, 1]
# print s.validUtf8(data)
#
# data = [235, 140, 4]
# print s.validUtf8(data)

data = [240, 162, 138, 147, 145]
print s.validUtf8(data)

