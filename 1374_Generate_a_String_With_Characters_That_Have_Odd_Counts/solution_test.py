
'''
1374. Generate a String With Characters That Have Odd Counts

Level: Easy

https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts
'''
import unittest

class TestSum(unittest.TestCase):

    def test_sum(self):
        self.assertEqual(sum([1, 2, 3]), 6, "Should be 6")

    def test_sum_tuple(self):
        self.assertEqual(sum((1, 2, 2)), 6, "Should be 6")

if __name__ == '__main__':
    unittest.main()