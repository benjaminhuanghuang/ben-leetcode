
'''
1296. Divide Array in Sets of K Consecutive Numbers

Level: Medium

https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers
'''
import unittest

class TestSum(unittest.TestCase):

    def test_sum(self):
        self.assertEqual(sum([1, 2, 3]), 6, "Should be 6")

    def test_sum_tuple(self):
        self.assertEqual(sum((1, 2, 2)), 6, "Should be 6")

if __name__ == '__main__':
    unittest.main()