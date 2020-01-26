package cn.huang.leetcode;

import java.util.ArrayList;

/*
	925	 Long Pressed Name
 */
public class LC_0925_LongPressedName {
    public boolean isLongPressedName(String name, String typed) {


        ArrayList<Character> chars_name = new ArrayList<>();
        ArrayList<Integer> charsCount_name = new ArrayList<>();
        ArrayList<Character> chars_typed = new ArrayList<>();
        ArrayList<Integer> charsCount_typed = new ArrayList<>();


        this.helper(name,chars_name, charsCount_name);
        this.helper(typed,chars_typed, charsCount_typed);

        if(chars_name.size() != chars_typed.size())
            return false;


        for(int i =0 ; i < chars_name.size(); i++) {
            if (charsCount_typed.get(i) < charsCount_name.get(i))
                return false;
        }
        return true;
    }

    private void helper(String s, ArrayList<Character> chars, ArrayList<Integer> counts)
    {
        int i = 0;
        int charLength = 0;
        char currChar = 0;



        while (i < s.length()) {
            if(currChar == 0) {
                currChar= s.charAt(i);
                charLength = 1;
            }
            else
            {
                if(currChar == s.charAt(i))
                {
                    charLength++;
                }
                else
                {
                    chars.add(currChar);
                    counts.add(charLength);

                    currChar = s.charAt(i);
                    charLength = 1;
                }
            }
            i ++;
        }
    }
}
