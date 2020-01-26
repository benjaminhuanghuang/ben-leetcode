package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*
68. Text Justification

Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and
is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces
' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide
evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

Note:

    A word is defined as a character sequence consisting of non-space characters only.
    Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
    The input array words contains at least one word.

Example 1:

Input:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]

Example 2:

Input:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be",
             because the last line must be left-justified instead of fully-justified.
             Note that the second line is also left-justified becase it contains only one word.

Example 3:

Input:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]


 */

/*
  单词排成行, 尽量均匀插入空格，最后用空格填充
 */
public class LC_0068_TextJustification {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> res = new ArrayList<>();
        int wordIdx = 0;

        while (wordIdx < words.length) {
            int count = words[wordIdx].length();
            int lastWord = wordIdx + 1;   // index of the last word can be put in current line
            while (lastWord < words.length) {
                if (words[lastWord].length() + count + 1 > maxWidth)   // + 1 is the space
                    break;
                count += 1 + words[lastWord].length();
                lastWord++;
            }
            StringBuilder sb = new StringBuilder();
            sb.append(words[wordIdx]);
            int diff = lastWord - wordIdx - 1;   // how many gap between words in line
            if (lastWord == words.length || diff == 0) {
                for (int i = wordIdx + 1; i < lastWord; i++) {
                    sb.append(" ");
                    sb.append(words[i]);
                }
                for (int i = sb.length(); i < maxWidth; i++) {
                    sb.append(" ");
                }
            } else {
                int spaces = (maxWidth - count) / diff;
                /*
                If the number of spaces on a line do not divide evenly between words, the empty slots on the left will
                be assigned more spaces than the slots on the right.
                 */
                int r = (maxWidth - count) % diff;
                for (int i = wordIdx + 1; i < lastWord; i++) {
                    for (int k = spaces; k > 0; k--) {
                        sb.append(" ");
                    }
                    if (r > 0) {
                        sb.append(" ");
                        r--;
                    }
                    sb.append(" ");
                    sb.append(words[i]);
                }
            }
            res.add(sb.toString());
            wordIdx = lastWord;
        }

        return res;
    }
}
