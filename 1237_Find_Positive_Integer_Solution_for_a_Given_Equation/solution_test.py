
'''
1237. Find Positive Integer Solution for a Given Equation

Level: Easy

https://leetcode.com/problems/find-positive-integer-solution-for-a-given-equation
'''
import unittest

class TestSum(unittest.TestCase):

    def test_sum(self):
        self.assertEqual(sum([1, 2, 3]), 6, "Should be 6")

    def test_sum_tuple(self):
        self.assertEqual(sum((1, 2, 2)), 6, "Should be 6")

if __name__ == '__main__':
    unittest.main()