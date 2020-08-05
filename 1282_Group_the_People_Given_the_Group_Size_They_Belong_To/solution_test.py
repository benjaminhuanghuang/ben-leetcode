
'''
1282. Group the People Given the Group Size They Belong To

Level: Medium

https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to
'''
import unittest

class TestSum(unittest.TestCase):

    def test_sum(self):
        self.assertEqual(sum([1, 2, 3]), 6, "Should be 6")

    def test_sum_tuple(self):
        self.assertEqual(sum((1, 2, 2)), 6, "Should be 6")

if __name__ == '__main__':
    unittest.main()