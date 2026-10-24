class Solution(object):
    def findPoisonedDuration(self, timeSeries, duration):
        """
        :type timeSeries: List[int]
        :type duration: int
        :rtype: int
        """
        if len(timeSeries) <= 0:
            return 0
        ans = 0
        last_start = timeSeries[0]
        last_end = timeSeries[0] + duration - 1
        for i in range(1, len(timeSeries)):
            if timeSeries[i] > last_end:
                ans += last_end - last_start + 1
                last_start = timeSeries[i]
                last_end = timeSeries[i] + duration - 1
            else:
                last_end = timeSeries[i] + last_start

        ans += last_end - last_start + 1
        return ans


s = Solution()
# print s.findPoisonedDuration([1, 4], 2)
print s.findPoisonedDuration([1, 2], 2)
