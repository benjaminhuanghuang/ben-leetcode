package cn.huang.leetcode;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

/*
648. Replace Words   [Uber]

 In English, we have a concept called root, which can be followed by some other words to form another longer word -
 let's call this word successor. For example, the root an, followed by other, which can form another word another.

Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence
with the root forming it. If a successor has many roots can form it, replace it with the root with the shortest length.

You need to output the sentence after the replacement.

Example 1:

Input: dict = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"

Note:

    The input will only have lower-case letters.
    1 <= dict words number <= 1000
    1 <= sentence words number <= 1000
    1 <= root length <= 100
    1 <= sentence words length <= 1000

 */
public class LC_0648_ReplaceWords {
    /*
    已知sentence和缩写list，把sentence中的word按照一定规则转换成其缩写，并返回sentence。
    用一个hashset存储缩写list中的元素，把sentence通过split(” “)分割成单词array，逐个单词对应查找其缩写并转换成其缩写，
    再把缩写后的单词array合成sentence并返回。

     */
    public String replaceWords(List<String> dict, String sentence) {
        Set<String> set = new HashSet<String>();
        set.addAll(dict);
        String Words[] = sentence.split(" ");
        String replaceWords = "";
        for (int i = 0; i < Words.length; i++)
            for (int j = 0; j < Words[i].length(); j++) //查找单词的缩写
                if (set.contains(Words[i].substring(0, j + 1))) {
                    //把单词转换成其缩写格式
                    Words[i] = Words[i].substring(0, j + 1);
                    break;
                } //合成replaceWords后的sentence
        for (int i = 0; i < Words.length; i++)
            replaceWords += (Words[i] + " ");
        return replaceWords.substring(0, replaceWords.length() - 1);
    }
}
