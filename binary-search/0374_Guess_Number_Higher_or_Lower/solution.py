def guess(num):
    n = 1
    if n < num:
        return -1
    elif n > num:
        return 1
    return 0


class Solution_my(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        low, high = 1, n
        while low + 1 < high:
            mid = (low + high) / 2
            if guess(mid) == 1:
                low = mid
            elif guess(mid) == -1:
                high = mid
            else:
                return mid
        if guess(low) == 0:
            return low
        return high


class Solution(object):
    def guessNumber_niave(self, n):
        """
        :type n: int
        :rtype: int
        """
        low, high = 1, n
        while low <= high:
            mid = (low + high) / 2
            if guess(mid) == 1:
                low = mid + 1
            elif guess(mid) == -1:
                high = mid
            else:
                return mid
                # return low

    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        low, high = 1, n
        while low < high:
            mid = (low + high) / 2
            if guess(mid) == 1:
                low = mid + 1
            else:
                high = mid
        return low


s = Solution()
print s.guessNumber_niave(1)
