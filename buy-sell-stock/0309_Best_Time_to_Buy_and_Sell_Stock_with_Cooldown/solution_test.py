
'''
309. Best Time to Buy and Sell Stock with Cooldown

Level: Medium

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown
'''
import unittest

class TestSum(unittest.TestCase):

    def test_sum(self):
        self.assertEqual(sum([1, 2, 3]), 6, "Should be 6")

    def test_sum_tuple(self):
        self.assertEqual(sum((1, 2, 2)), 6, "Should be 6")

if __name__ == '__main__':
    unittest.main()