'''
394. Decode String

Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly
k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those
repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

'''
import collections


class Solution(object):
    # http://bookshadow.com/weblog/2016/09/04/leetcode-decode-string/
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        k = 1
        parts = collections.defaultdict(str)
        digits = collections.defaultdict(int)
        for c in s:
            if c.isdigit():
                # for multi-digits int
                digits[k] = digits[k] * 10 + int(c)
            elif c == '[':
                k += 1
            elif c == ']':
                parts[k - 1] += digits[k - 1] * parts[k]
                digits[k - 1] = 0
                parts[k] = ''
                k -= 1
            else:
                parts[k] += c

        return parts[1]

    # https://all4win78.wordpress.com/2016/09/07/leetcode-394-decode-string/
    def decodeString_better(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s:
            return ""

        res = ""
        int_stack = []
        str_statck = []
        repeat = 0
        for c in s:
            if c.isdigit():
                # for multi-digits int
                repeat = repeat * 10 + int(c)
            elif c == '[':
                str_statck.append(res)
                res = ""

                int_stack.append(repeat)
                repeat = 0
            elif c == ']':
                curr_str = res
                res = str_statck.pop()
                repeat = int_stack.pop()
                res += curr_str * repeat
                repeat = 0
            else:
                res += c

        return res

    def decodeString_wrong(self, s):
        """
        :type s: str
        :rtype: str
        """
        digit_key = 1
        str_key = 1
        str_parts = collections.defaultdict(str)
        digits = collections.defaultdict(int)
        for c in s:
            if c.isdigit():
                # for multi-digits int
                digits[digit_key] = digits[digit_key] * 10 + int(c)
            elif c == '[':
                str_key += 1
            elif c == ']':
                str_parts[str_key] += digits[digit_key] * str_parts[str_key]
                digits[digit_key] = 0
                str_parts[str_key] = ''
                str_key -= 1
                digit_key -= 1
            else:
                str_parts[str_key] += c

        return str_parts[1]


solution = Solution()
s = "2[abc]3[cd]ef"
# s = "3[a2[c]]"
# s = "10[leetcode]"
s = "3[a]2[bc]"
print solution.decodeString_better(s)
