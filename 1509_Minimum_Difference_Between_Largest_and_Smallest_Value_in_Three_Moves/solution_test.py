
'''
1509. Minimum Difference Between Largest and Smallest Value in Three Moves

Level: Medium

https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves
'''
import unittest

class TestSum(unittest.TestCase):

    def test_sum(self):
        self.assertEqual(sum([1, 2, 3]), 6, "Should be 6")

    def test_sum_tuple(self):
        self.assertEqual(sum((1, 2, 2)), 6, "Should be 6")

if __name__ == '__main__':
    unittest.main()