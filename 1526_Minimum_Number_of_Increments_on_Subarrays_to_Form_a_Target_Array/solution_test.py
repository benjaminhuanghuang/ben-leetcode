
'''
1526. Minimum Number of Increments on Subarrays to Form a Target Array

Level: Hard

https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array
'''
import unittest

class TestSum(unittest.TestCase):

    def test_sum(self):
        self.assertEqual(sum([1, 2, 3]), 6, "Should be 6")

    def test_sum_tuple(self):
        self.assertEqual(sum((1, 2, 2)), 6, "Should be 6")

if __name__ == '__main__':
    unittest.main()