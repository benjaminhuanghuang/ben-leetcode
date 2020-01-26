package cn.huang.leetcode;

import java.util.HashSet;

/*
    804. Unique Morse Code Words
    International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes,
    as follows: "a" maps to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.

    For convenience, the full table for the 26 letters of the English alphabet is given below:

    [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
    Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter.
    For example, "cba" can be written as "-.-..--...", (which is the concatenation "-.-." + "-..." + ".-"). We'll call such a concatenation, the transformation of a word.

    Return the number of different transformations among all words we have.

    Example:
    Input: words = ["gin", "zen", "gig", "msg"]
    Output: 2
    Explanation:
    The transformation of each word is:
    "gin" -> "--...-."
    "zen" -> "--...-."
    "gig" -> "--...--."
    "msg" -> "--...--."

    There are 2 different transformations, "--...-." and "--...--.".
 */
public class LC_0804_UniqueMorseCodeWords {
    private String[] morse = new String[]{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    public int uniqueMorseRepresentations(String[] words) {
        HashSet<String> set = new HashSet<>();

        for(int i =0 ;i < words.length;i ++)
        {
            String morseWord = getMorseWord(words[i]);
            set.add(morseWord);
        }
        return set.size();
    }

    private String getMorseWord(String word)
    {
        String res = "";
        for(int i = 0; i < word.length(); i++)
        {
            res = res + morse[word.charAt(i) - 'a'];
        }
        return res;
    }
}

