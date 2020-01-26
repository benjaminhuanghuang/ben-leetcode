package cn.huang.leetcode;

/*
736. Parse Lisp Expression


 */

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;

/*

 */
public class LC_0736_ParseLispExpression {
    public int evaluate(String expression) {
        HashMap<String, Integer> bl = new HashMap<>();
        int res = help(expression, bl);
        return res;
    }

    private Integer help(String ex, HashMap<String, Integer> bl) {
        if (ex.startsWith("(")) {
            String tmp = ex.substring(1, ex.length() - 1);
            String[] els = deal(tmp);
            if (els[0].equals("let")) {
                for (int i = 1; i < els.length - 1; i += 2) {
                    bl.put(els[i], help(els[i + 1], new HashMap<>(bl)));
                }
                return help(els[els.length - 1], new HashMap<>(bl));
            } else if (els[0].equals("add")) {
                return help(els[1], new HashMap<>(bl)) + help(els[2], new HashMap<>(bl));
            } else {
                return help(els[1], new HashMap<>(bl)) * help(els[2], new HashMap<>(bl));
            }
        } else {
            if (Character.isDigit(ex.charAt(0)) || ex.charAt(0) == '-') {
                return Integer.parseInt(ex);
            } else {
                return bl.get(ex);
            }
        }
    }

    private String[] deal(String tmp) {
        ArrayList<String> ret = new ArrayList<>();
        String[] els = tmp.split(" ");
        for (int i = 0; i < els.length; ) {
            if (!els[i].startsWith("(")) {
                ret.add(els[i++]);
            } else {
                StringBuilder el = new StringBuilder(els[i]);
                LinkedList<String> stack = new LinkedList<>();
                stack.addFirst(els[i++]);
                while (!stack.isEmpty() && i < els.length) {
                    if (els[i].startsWith("(")) {
                        stack.addFirst(els[i]);
                    }
                    int k = els[i].length() - 1;
                    while (k >= 0) {
                        if (els[i].charAt(k--) != ')')
                            break;
                        stack.removeFirst();
                    }
                    el.append(" ").append(els[i++]);
                }
                ret.add(el.toString());
            }
        }
        return ret.toArray(new String[ret.size()]);
    }
}
