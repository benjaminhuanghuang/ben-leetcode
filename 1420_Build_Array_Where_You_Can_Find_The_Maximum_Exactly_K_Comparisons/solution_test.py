
'''
1420. Build Array Where You Can Find The Maximum Exactly K Comparisons

Level: Hard

https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons
'''
import unittest

class TestSum(unittest.TestCase):

    def test_sum(self):
        self.assertEqual(sum([1, 2, 3]), 6, "Should be 6")

    def test_sum_tuple(self):
        self.assertEqual(sum((1, 2, 2)), 6, "Should be 6")

if __name__ == '__main__':
    unittest.main()