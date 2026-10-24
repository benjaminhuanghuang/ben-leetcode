'''
17. Letter Combinations of a Phone Number

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.


Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
'''


class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if not digits or len(digits) <= 0:
            return []

        dict = {'2': ['a', 'b', 'c'],
                '3': ['d', 'e', 'f'],
                '4': ['g', 'h', 'i'],
                '5': ['j', 'k', 'l'],
                '6': ['m', 'n', 'o'],
                '7': ['p', 'q', 'r', 's'],
                '8': ['t', 'u', 'v'],
                '9': ['w', 'x', 'y', 'z']}

        def dfs(num, res, substr):
            if num == len(digits):
                res.append(substr)
                return
            for letter in dict[digits[num]]:
                dfs(num + 1, res, substr + letter)

        solution = []
        dfs(0, solution, "")
        return solution

    def letterCombinations_2(self, digits):
        if '' == digits: return []
        kvmaps = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz'
        }
        return reduce(lambda acc, digit: [x + y for x in acc for y in kvmaps[digit]], digits, [''])


class SolutionMy(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """

        if not digits or len(digits) <= 0:
            return []

        self.dict = {'2': ['a', 'b', 'c'],
                     '3': ['d', 'e', 'f'],
                     '4': ['g', 'h', 'i'],
                     '5': ['j', 'k', 'l'],
                     '6': ['m', 'n', 'o'],
                     '7': ['p', 'q', 'r', 's'],
                     '8': ['t', 'u', 'v'],
                     '9': ['w', 'x', 'y', 'z']}
        self.solution = []
        self.dfs(0, "", digits)
        return self.solution

    def dfs(self, pos, combination, digits):
        if len(combination) == len(digits):
            self.solution.append(combination)
            return
        for c in self.dict[digits[pos]]:
            tmp = combination + c
            self.dfs(pos + 1, tmp, digits)


solution = SolutionMy()
rest = solution.letterCombinations("24")
print rest
