
'''
1437. Check If All 1's Are at Least Length K Places Away

Level: Medium

https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away
'''
import unittest

class TestSum(unittest.TestCase):

    def test_sum(self):
        self.assertEqual(sum([1, 2, 3]), 6, "Should be 6")

    def test_sum_tuple(self):
        self.assertEqual(sum((1, 2, 2)), 6, "Should be 6")

if __name__ == '__main__':
    unittest.main()