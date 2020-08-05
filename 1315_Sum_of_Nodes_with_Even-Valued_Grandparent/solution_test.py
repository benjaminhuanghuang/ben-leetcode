
'''
1315. Sum of Nodes with Even-Valued Grandparent

Level: Medium

https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent
'''
import unittest

class TestSum(unittest.TestCase):

    def test_sum(self):
        self.assertEqual(sum([1, 2, 3]), 6, "Should be 6")

    def test_sum_tuple(self):
        self.assertEqual(sum((1, 2, 2)), 6, "Should be 6")

if __name__ == '__main__':
    unittest.main()