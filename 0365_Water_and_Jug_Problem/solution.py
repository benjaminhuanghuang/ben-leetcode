'''
365. Water and Jug Problem


You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available.
You need to determine whether it is possible to measure exactly z litres using these two jugs.

If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.

Operations allowed:

Fill any of the jugs completely with water.
Empty any of the jugs.
Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.

Example 1: (From the famous "Die Hard" example)
    Input: x = 3, y = 5, z = 4
    Output: True

Example 2:
    Input: x = 2, y = 6, z = 5
    Output: False

'''


class Solution(object):
    def gcd(self, a, b):
        return a if b == 0 else self.gcd(b, a % b)

    def canMeasureWater(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: bool
        """
        return x + y == z or ((x + y > z) and z % self.gcd(x, y) == 0)


s = Solution()
print s.gcd(70, 15)
