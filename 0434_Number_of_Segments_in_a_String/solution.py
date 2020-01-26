'''
434. Number of Segments in a String

Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5
'''


class Solution(object):
    def countSegments_my(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        s = s.strip()

        res = 0
        in_seg = False
        for c in s:
            if c == " ":
                if in_seg:
                    res += 1
                    in_seg = False
            else:
                in_seg = True
        if in_seg:
            res += 1
        return res

    def countSegments_wrong(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        s = s.strip()
        if s:
            s_arr = s.split(" ")
            return len(s_arr)
        return 0


input = ", , , ,        a, eaefa"
s = Solution()
res = s.countSegments("         ")
print res
