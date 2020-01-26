'''
500. Keyboard Row

Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.

Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.
'''


class Solution(object):
    def findWords_my(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        line1 = set(['q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'])
        line2 = set(['a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'])
        line3 = set(['z', 'x', 'c', 'v', 'b', 'n', 'm'])
        result = []
        for word in words:
            w = word.lower()
            c_set = set(list(w))
            if c_set.issubset(line1) or c_set.issubset(line2) or c_set.issubset(line3):
                result.append(word)

        return result

    def findWords_better(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        row_sets = map(set, ['qwertyuiop', 'asdfghjkl', 'zxcvbnm'])
        ans = []
        for word in words:
            wset = set(word.lower())
            if any(wset <= rset for rset in row_sets):
                ans.append(word)
        return ans
