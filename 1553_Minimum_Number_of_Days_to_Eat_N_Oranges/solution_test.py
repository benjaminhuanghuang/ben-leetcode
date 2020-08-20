
'''
1553. Minimum Number of Days to Eat N Oranges

Level: Hard

https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges
'''
import unittest

class TestSum(unittest.TestCase):

    def test_sum(self):
        self.assertEqual(sum([1, 2, 3]), 6, "Should be 6")

    def test_sum_tuple(self):
        self.assertEqual(sum((1, 2, 2)), 6, "Should be 6")

if __name__ == '__main__':
    unittest.main()