'''
60. Permutation Sequence

The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
'''

import math


class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        return self.helper([x + 1 for x in range(n)], n, k)

    def helper(self, nums, n, k):
        if n == 1:
            return str(nums[0])

        i = (k - 1) / math.factorial(n - 1)
        return str(nums[i]) + self.helper(nums[:i] + nums[i + 1:], n - 1, (k - 1) % math.factorial(n - 1) + 1)

    def getPermutation_9(self, n, k):
        fac = [1]
        for i in range(1, n + 1):
            fac.append(fac[-1] * i)

        elegible = range(1, n + 1)
        per = []
        for i in range(n):
            digit = (k - 1) / fac[n - i - 1]
            per.append(elegible[digit])
            elegible.remove(elegible[digit])
            k = (k - 1) % fac[n - i - 1] + 1
        return "".join([str(x) for x in per])

    # https://www.hrwhisper.me/leetcode-permutations/
    def getPermutation_2(self, n, k):
        factorial, ans = 1, [0 for x in range(n)]
        for i in range(n):
            factorial *= i + 1
            ans[i] += i + 1

        k = k - 1
        for i in range(n):
            factorial /= n - i
            index = i + k / factorial
            cur, j = ans[index], index
            while j > i:
                ans[j] = ans[j - 1]
                j -= 1
            k %= factorial
            ans[i] = cur

        return ''.join(str(i) for i in ans)

    def getPermutation_2_improve(self, n, k):
        factorial = math.factorial(n)
        ans = range(1, n + 1)

        k = k - 1
        for i in range(n):
            factorial /= n - i
            index = i + k / factorial
            cur, j = ans[index], index
            while j > i:
                ans[j] = ans[j - 1]
                j -= 1
            k %= factorial
            ans[i] = cur

        return ''.join(str(i) for i in ans)


print math.factorial(9)

n = 9
k = 2
s = Solution()
print s.getPermutation_9(n, k)
