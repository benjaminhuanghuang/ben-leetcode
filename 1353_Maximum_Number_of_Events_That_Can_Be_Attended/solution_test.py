
'''
1353. Maximum Number of Events That Can Be Attended

Level: Medium

https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended
'''
import unittest

class TestSum(unittest.TestCase):

    def test_sum(self):
        self.assertEqual(sum([1, 2, 3]), 6, "Should be 6")

    def test_sum_tuple(self):
        self.assertEqual(sum((1, 2, 2)), 6, "Should be 6")

if __name__ == '__main__':
    unittest.main()