package cn.huang.leetcode;

/*
809. Expressive Words

Sometimes people repeat letters to represent extra feeling, such as "hello" -> "heeellooo", "hi" -> "hiiii".
Here, we have groups, of adjacent letters that are all the same character, and adjacent characters to the group are
different.
A group is extended if that group is length 3 or more, so "e" and "o" would be extended in the first example,
and "i" would be extended in the second example.  As another example, the groups of "abbcccaaaa" would be "a", "bb", "ccc",
and "aaaa"; and "ccc" and "aaaa" are the extended groups of that string.

For some given string S, a query word is stretchy if it can be made to be equal to S by extending some groups.
Formally, we are allowed to repeatedly choose a group (as defined above) of characters c, and add some number of the
same character c to it so that the length of the group is 3 or more.  Note that we cannot extend a group of size one
like "h" to a group of size two like "hh" - all extensions must leave the group extended - ie., at least 3 characters long.

Given a list of query words, return the number of words that are stretchy.

Example:
Input:
S = "heeellooo"
words = ["hello", "hi", "helo"]
Output: 1
Explanation:
We can extend "e" and "o" in the word "hello" to get "heeellooo".
We can't extend "helo" to get "heeellooo" because the group "ll" is not extended.

Notes:

    0 <= len(S) <= 100.
    0 <= len(words) <= 100.
    0 <= len(words[i]) <= 100.
    S and all words in words consist only of lowercase letters

 */
public class LC_0809_ExpressiveWords {
    /*
    http://www.cnblogs.com/grandyang/p/9426942.html

    给了一个拉伸后的单词S和一个单词数组，问里面有多少个单词可以拉伸成为S。
     */
    public int expressiveWords(String S, String[] words) {
        int res = 0;
        for (String word : words) {
            int i = 0, j = 0;
            for (; i < S.length(); ++i) { // iterate chars in S
                if (j < word.length() && S.charAt(i) == word.charAt(j))
                    ++j;
                else if (i > 0 && S.charAt(i) == S.charAt(i - 1) && i + 1 < S.length() && S.charAt(i) == S.charAt(i + 1))
                    ++i;
                else if (!(i > 1 && S.charAt(i) == S.charAt(i - 1) && S.charAt(i) == S.charAt(i - 2)))
                    break;
            }
            if (i == S.length() && j == word.length())  // pass
                ++res;
        }
        return res;
    }
}
