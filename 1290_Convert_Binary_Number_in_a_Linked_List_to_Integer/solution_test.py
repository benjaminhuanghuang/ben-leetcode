
'''
1290. Convert Binary Number in a Linked List to Integer

Level: Easy

https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer
'''
import unittest

class TestSum(unittest.TestCase):

    def test_sum(self):
        self.assertEqual(sum([1, 2, 3]), 6, "Should be 6")

    def test_sum_tuple(self):
        self.assertEqual(sum((1, 2, 2)), 6, "Should be 6")

if __name__ == '__main__':
    unittest.main()