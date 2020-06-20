
'''
1317. Convert Integer to the Sum of Two No-Zero Integers

Level: Easy

https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers
'''
import unittest

class TestSum(unittest.TestCase):

    def test_sum(self):
        self.assertEqual(sum([1, 2, 3]), 6, "Should be 6")

    def test_sum_tuple(self):
        self.assertEqual(sum((1, 2, 2)), 6, "Should be 6")

if __name__ == '__main__':
    unittest.main()