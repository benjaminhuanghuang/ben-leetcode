'''
68. Text Justification

Given an array of words and a length L, format the text such that each line has exactly L characters and is
fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad
extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line
do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots
on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.
'''


class Solution(object):
    #  First try:
    def fullJustify_first(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        res = []
        line = []
        words_width_in_line = 0
        i = 0
        while i < len(words):
            word = words[i]
            word_width = len(word)

            if i == len(words) - 1:
                if words_width_in_line + word_width > maxWidth - len(line):
                    spaces = maxWidth - words_width_in_line
                    res.append(self.join_words(line, spaces, maxWidth, False))

                    spaces = maxWidth - word_width
                    res.append(self.join_words([word], spaces, maxWidth, True))

                else:
                    line.append(word)
                    words_width_in_line += len(word)
                    spaces = maxWidth - words_width_in_line
                    res.append(self.join_words(line, spaces, maxWidth, True))
                break
            else:
                if words_width_in_line + word_width > maxWidth - len(line):
                    spaces = maxWidth - words_width_in_line
                    res.append(self.join_words(line, spaces, maxWidth, False))
                    words_width_in_line = len(word)
                    line = [word]
                    i += 1
                else:
                    line.append(word)
                    words_width_in_line += len(word)
                    i += 1

        return res

    def join_words(self, line, spaces, maxWidth, is_last_line):
        res = ""
        if is_last_line:
            for i in xrange(len(line)):
                res += line[i]
                if i < len(line) - 1 and len(line) > 1:
                    res += " "
            if len(res) < maxWidth:
                res += " " * (maxWidth - len(res))
        else:
            if len(line) == 1:
                res = line[0] + " " * (maxWidth - len(line[0]))
            else:
                i = 0
                while i < spaces:
                    for j in xrange(len(line) - 1):
                        line[j] = line[j] + " "
                        i += 1
                        if i >= spaces:
                            break
                res = "".join(line)
        return res

    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        ans = []
        i = 0
        while i < len(words):
            size = 0
            begin = i
            while i < len(words):
                if size == 0:
                    newsize = len(words[i])
                else:
                    newsize = size + len(words[i]) + 1
                if newsize <= maxWidth:
                    size = newsize
                else:
                    break
                i += 1
            spaceCnt = maxWidth - size
            if i - begin - 1 > 0 and i < len(words):
                everyCount = spaceCnt // (i - begin - 1)
                spaceCnt %= i - begin - 1
            else:
                everyCount = 0
            j = begin;
            s = ""
            while j < i:
                if j == begin:
                    s = words[j]
                else:
                    s += ' ' * (everyCount + 1)
                    if spaceCnt > 0 and i < len(words):
                        s += ' '
                        spaceCnt -= 1
                    s += words[j]
                j += 1
            s += ' ' * spaceCnt
            ans.append(s)
        return ans


words = [""]
width = 2

words = ["This", "is", "an", "example", "of", "text", "justification."]
width = 16
# width = 14

# words = ["What", "must", "be", "shall", "be."]
# width = 12
# words = ["a", "b", "c", "d", "e"]print s.fullJustify_first(words, width)
# width = 1

# words = ["Listen", "to", "many,", "speak", "to", "a", "few."]
# width = 6

s = Solution()
# print s.fullJustify_first(words, width)

print s.fullJustify(words, width)
