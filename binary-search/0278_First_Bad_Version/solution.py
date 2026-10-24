def isBadVersion(n):
    return False


class Solution(object):

    #  2 versions
    #  2 is the first bad version.
    def firstBadVersion_wrong(self, n):
        """
        :type n: int
        :rtype: int
        """
        start, end = 1, n
        while start < end:     # => start + 1 < end:
            mid = (start + end) / 2
            if isBadVersion(mid):
                end = mid
            else:
                start = mid    # infinite loop
        if isBadVersion(start):
            return start
        return end

    def firstBadVersion_my(self, n):
        """
        :type n: int
        :rtype: int
        """
        start, end = 1, n


        while start + 1 < end:
            mid = (start + end) / 2
            if isBadVersion(mid):
                end = mid
            else:
                start = mid
        return end

    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        start, end = 1, n
        while start + 1 < end:
            mid = (start + end) / 2
            if isBadVersion(mid):
                end = mid
            else:
                start = mid
        if isBadVersion(start):
            return start
        return end
