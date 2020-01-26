package cn.huang.leetcode;

import java.util.HashMap;
import java.util.Map;

/*
    383. Ransom Note
    Given an arbitrary ransom note string and another string containing letters from all the magazines,
    write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

    Each letter in the magazine string can only be used once in your ransom note.

    Note:
    You may assume that both strings contain only lowercase letters.

    canConstruct("a", "b") -> false
    canConstruct("aa", "ab") -> false
    canConstruct("aa", "aab") -> true
 */
public class LC_0383_RansomNote {
    public boolean canConstruct(String ransomNote, String magazine) {
        Map<Character, Integer> magazineChars = new HashMap<Character, Integer>();
        for (Character c : magazine.toCharArray()) {
            if (magazineChars.containsKey(c)) {
                magazineChars.put(c, magazineChars.get(c) + 1);
            } else {
                magazineChars.put(c, 1);
            }
        }

        for (Character c : ransomNote.toCharArray()) {
            if (magazineChars.containsKey(c)) {
                int count = magazineChars.get(c) - 1;
                if (count < 0) {
                    return false;
                }
                magazineChars.put(c, count);
            } else {
                return false;
            }
        }
        return true;
    }

    public boolean canConstruct_v2(String ransomNote, String magazine) {
        int[] magazineChars = new int[128];
        for (Character c : magazine.toCharArray()) {
            magazineChars[c]++;
        }

        for (Character c : ransomNote.toCharArray()) {
            if(magazineChars[c] == 0)
                return false;
            magazineChars[c]--;

        }
        return true;
    }
}
