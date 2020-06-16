
'''
1460. Make Two Arrays Equal by Reversing Sub-arrays

Level: Easy

https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays
'''
import unittest

class TestSum(unittest.TestCase):

    def test_sum(self):
        self.assertEqual(sum([1, 2, 3]), 6, "Should be 6")

    def test_sum_tuple(self):
        self.assertEqual(sum((1, 2, 2)), 6, "Should be 6")

if __name__ == '__main__':
    unittest.main()