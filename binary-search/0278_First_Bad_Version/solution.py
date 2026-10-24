'''
278. First Bad Version

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of
your product fails the quality check. Since each version is developed based on the previous version, all the versions
after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following
ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find
the first bad version. You should minimize the number of calls to the API.

'''


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
