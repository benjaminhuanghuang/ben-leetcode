'''
393. UTF-8 Validation

A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:
    For 1-byte character, the first bit is a 0, followed by its unicode code.

    For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed by n-1 bytes with most significant
    2 bits being 10.

This is how the UTF-8 encoding would work:

   Char. number range  |        UTF-8 octet sequence
      (hexadecimal)    |              (binary)
   --------------------+---------------------------------------------
   0000 0000-0000 007F | 0xxxxxxx
   0000 0080-0000 07FF | 110xxxxx 10xxxxxx
   0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
   0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
Given an array of integers representing the data, return whether it is a valid utf-8 encoding.

Note:
The input is an array of integers. Only the least significant 8 bits of each integer is used to store the data.
This means each integer represents only 1 byte of data.

Example 1:

data = [197, 130, 1], which represents the octet sequence: 11000101 10000010 00000001.

Return true.
It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.
Example 2:

data = [235, 140, 4], which represented the octet sequence: 11101011 10001100 00000100.

Return false.
The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes character.
The next byte is a continuation byte which starts with 10 and that's correct.
But the second continuation byte does not start with 10, so it is invalid.
'''


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

