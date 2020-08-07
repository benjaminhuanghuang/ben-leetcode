
'''
1415. The k-th Lexicographical String of All Happy Strings of Length n

Level: Medium

https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n
'''
import unittest

class TestSum(unittest.TestCase):

    def test_sum(self):
        self.assertEqual(sum([1, 2, 3]), 6, "Should be 6")

    def test_sum_tuple(self):
        self.assertEqual(sum((1, 2, 2)), 6, "Should be 6")

if __name__ == '__main__':
    unittest.main()