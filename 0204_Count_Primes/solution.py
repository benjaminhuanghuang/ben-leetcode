'''
204. Count Primes

Description:

Count the number of prime numbers less than a non-negative number, n.

Hint:

https://leetcode.com/problems/count-primes/

Let's start with a isPrime function. To determine if a number is prime, we need to check if it is not divisible by any
number less than n. The runtime complexity of isPrime function would be O(n) and hence counting the total prime numbers
up to n would be O(n2). Could we do better?

As we know the number must not be divisible by any number > n / 2, we can immediately cut the total iterations half by
dividing only up to n / 2. Could we still do better?


'''


class Solution(object):
    # https://www.youtube.com/watch?v=whwlDCExMpY

    # Time Limit Exceeded
    def countPrimes_easy(self, n):
        """
        :type n: int
        :rtype: int
        """

        result = []
        for i in range(2, n):
            if self.isPrime(i):
                result.append(i)

        return len(result)

    def isPrime(self, n):
        if n == 2:
            return True
        elif n < 2 or not n & 1:  # n & 1 == 0 means n is odd number
            return False

        for i in range(3, int(n ** 0.5) + 1, 2):
            if n % i == 0:
                return False

        return True

    #  Sieve of Eratosthenes
    def countPrimes(self, n):
        if n <= 2:
            return 0
        isPrimes = [True] * n  # A[0] to A[n -1]

        for i in xrange(2, int(n ** 0.5) + 1):
            if isPrimes[i]:
                for j in xrange(i*i, n, i):  # remove all multiple of i, i*(i+i) to n
                    isPrimes[j] = False
        return sum(isPrimes) - 2  # skip A[0] and A[1]
