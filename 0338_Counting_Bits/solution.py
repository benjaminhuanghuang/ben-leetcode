'''
338. Counting Bits

Level: Medium

https://leetcode.com/problems/counting-bits

Given a non negative integer number num. For every numbers i in the range 0 <= i <= num calculate the number of 1's in
their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n)
/possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
'''


class Solution(object):
    # https://www.hrwhisper.me/leetcode-counting-bits/
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        res = [0] * (num + 1)
        before = pow2 = 1
        for i in xrange(1, num + 1):
            if i == pow2:
                before = res[i] = 1
                pow2 <<= 1
            else:
                res[i] = res[before] + 1
                before += 1
        return res

    # https://oncemore2020.github.io/blog/leetcode-338/
    # ans[n] = ans[n >> 1] + (n & 1)
    def countBits_2(self, num):
        ans = [0]
        for x in range(1, num + 1):
            ans += [ans[x >> 1] + (x & 1)]
        return ans


s = Solution()
print s.countBits_2(2)