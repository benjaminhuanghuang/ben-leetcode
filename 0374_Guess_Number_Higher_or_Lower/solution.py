'''
374. Guess Number Higher or Lower

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
Example:
n = 10, I pick 6.

Return 6.
'''


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
