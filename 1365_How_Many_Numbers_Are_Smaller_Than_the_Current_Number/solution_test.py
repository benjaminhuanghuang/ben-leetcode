
'''
1365. How Many Numbers Are Smaller Than the Current Number

Level: Easy

https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number
'''
import unittest

class TestSum(unittest.TestCase):

    def test_sum(self):
        self.assertEqual(sum([1, 2, 3]), 6, "Should be 6")

    def test_sum_tuple(self):
        self.assertEqual(sum((1, 2, 2)), 6, "Should be 6")

if __name__ == '__main__':
    unittest.main()