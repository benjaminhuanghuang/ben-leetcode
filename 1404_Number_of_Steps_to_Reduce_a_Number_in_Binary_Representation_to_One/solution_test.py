
'''
1404. Number of Steps to Reduce a Number in Binary Representation to One

Level: Medium

https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one
'''
import unittest

class TestSum(unittest.TestCase):

    def test_sum(self):
        self.assertEqual(sum([1, 2, 3]), 6, "Should be 6")

    def test_sum_tuple(self):
        self.assertEqual(sum((1, 2, 2)), 6, "Should be 6")

if __name__ == '__main__':
    unittest.main()