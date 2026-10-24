class Solution(object):
    # 10 LED can present 0 to 1024
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        ans = []
        for x in range(1024):
            # bin convert int to a bin string
            if bin(x).count('1') == num:
                ans += self.parseTime(x)
        return ans

    def parseTime(self, num):
        hour, minute = num >> 6, num & 0x3F  # 111111
        if hour > 11 or minute > 59:
            return []
        return [str(hour) + ':' + str(minute).zfill(2)]
