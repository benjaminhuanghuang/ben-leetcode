package cn.huang.leetcode;
/*
966. Vowel Spellchecker

Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.

For a given query word, the spell checker handles two categories of spelling mistakes:

    Capitalization: If the query matches a word in the wordlist (case-insensitive), then the query word is returned
    with the same case as the case in the wordlist.
        Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
        Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
        Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
    Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word with any vowel individually,
    it matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the match in the wordlist.
        Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
        Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
        Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)

In addition, the spell checker operates under the following precedence rules:

    When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
    When the query matches a word up to capitlization, you should return the first such match in the wordlist.
    When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
    If the query has no matches in the wordlist, you should return the empty string.

Given some queries, return a list of words answer, where answer[i] is the correct word for query = queries[i].



Example 1:

Input: wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]



Note:

    1 <= wordlist.length <= 5000
    1 <= queries.length <= 5000
    1 <= wordlist[i].length <= 7
    1 <= queries[i].length <= 7
    All strings in wordlist and queries consist only of english letters.


 */

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/*
给定一个wordlist，其中包含了若干个单词（只包含英文字母的字符串），给定一系列query，要求从wordlist中找出匹配单词：

    如果wordlist中包含单词与该query相同，则直接返回query
    如果在不考虑大小写的情况下，wordlist中包含单词与该query相同（例："AbC"和"aBc"是相同的），则返回第一个匹配单词
    如果在不考虑大小写和将所有元音字母认为是同一个字母的情况下，wordlist中包含单词与该query相同（例："Aab"与"eIb"是相同的），则返回第一个匹配单词

    首先，判断有没有相同的单词，这个很好办，直接使用set;
    其次，要判断改变某些大小写，这里注意的是可以把要查询的字符串中的任意字符转换成大小写，如果抽象一点的话就是，忽略字符串所有字符的大小写之后匹配即可。因为要返回第一个出现的，所以，我们把要字典字符串反过来构成字典，这样就保存了忽略大小写之后的字符串第一个出现的位置。
    最后，要把元音字符进行忽略，可以任意转换。这个思路很邪，直接把元音字符转成同样的字符，这样只要把元音统一替换之后的结果相等即可。同样反向构成字典。

 */
public class LC_0966_VowelSpellchecker {
    public String[] spellchecker(String[] wordlist, String[] queries) {
        Set<String> set = new HashSet<>();
        Map<String, Integer> map1 = new HashMap<>();
        Map<String, Integer> map2 = new HashMap<>();
        for (int i = 0; i < wordlist.length; i++) {
            set.add(wordlist[i]);
            StringBuilder sb = new StringBuilder();
            StringBuilder sb1 = new StringBuilder();
            for (int j = 0; j < wordlist[i].length(); j++) {
                char c = Character.toLowerCase(wordlist[i].charAt(j));
                sb.append(c);
                if (!judge(c)) sb1.append(c);
                else sb1.append('#');
            }
            String temp = sb.toString();
            if (!map1.containsKey(temp)) map1.put(temp, i);
            String temp1 = sb1.toString();
            if (!map2.containsKey(temp1)) map2.put(temp1, i);
        }
        String[] res = new String[queries.length];
        for (int i = 0; i < queries.length; i++) {
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < queries[i].length(); j++) {
                char c = Character.toLowerCase(queries[i].charAt(j));
                if (!judge(c)) sb.append(c);
                else sb.append('#');
            }
            String temp = sb.toString();
            if (set.contains(queries[i])) res[i] = queries[i];
            else if (map1.containsKey(queries[i].toLowerCase())) res[i] = wordlist[map1.get(queries[i].toLowerCase())];
            else if (map2.containsKey(temp)) res[i] = wordlist[map2.get(temp)];
            else res[i] = "";
        }
        return res;
    }

    public boolean judge(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}
