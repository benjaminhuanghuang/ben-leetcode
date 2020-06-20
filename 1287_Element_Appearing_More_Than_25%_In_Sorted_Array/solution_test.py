
'''
1287. Element Appearing More Than 25% In Sorted Array

Level: Easy

https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array
'''
import unittest

class TestSum(unittest.TestCase):

    def test_sum(self):
        self.assertEqual(sum([1, 2, 3]), 6, "Should be 6")

    def test_sum_tuple(self):
        self.assertEqual(sum((1, 2, 2)), 6, "Should be 6")

if __name__ == '__main__':
    unittest.main()