package cn.huang.leetcode;

import java.util.*;

/*
990. Satisfiability of Equality Equations

Given an array equations of strings that represent relationships between variables, each string equations[i] has
length 4 and takes one of two different forms: "a==b" or "a!=b".  Here, a and b are lowercase letters
(not necessarily different) that represent one-letter variable names.

Return true if and only if it is possible to assign integers to variable names so as to satisfy all the given equations.



Example 1:

Input: ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
There is no way to assign the variables to satisfy both equations.
Example 2:

Input: ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
Example 3:

Input: ["a==b","b==c","a==c"]
Output: true
Example 4:

Input: ["a==b","b!=c","c==a"]
Output: false
Example 5:

Input: ["c==c","b==d","x!=z"]
Output: true


Note:

1 <= equations.length <= 500
equations[i].length == 4
equations[i][0] and equations[i][3] are lowercase letters
equations[i][1] is either '=' or '!'
equations[i][2] is '='
 */
public class LC_0990_SatisfiabilityofEqualityEquations {
    /*
    Solution: Union Find

    Time complexity: O(n)
    Space complexity: O(1)

    https://zxi.mytechroad.com/blog/graph/leetcode-990-satisfiability-of-equality-equations/

    First pass: x==y, merge(x,y)
    Second pass: x!=y, assert(find(x)!=find(y)
     */

    private int[] parents = new int[128];   //

    public boolean equationsPossible(String[] equations) {
        if (equations.length == 1) {
            return true;
        }
        // init
        for (int i = 0; i < 128; i++) {
            parents[i] = i;
        }

        // Pass 1
        for (String eq : equations) {
            if (eq.charAt(1) == '=') {
                parents[find(eq.charAt(0))] = find(eq.charAt(3));
            }
        }
        // Pass 2
        for (String eq : equations) {
            if (eq.charAt(1) == '!' && (find(eq.charAt(0)) == find(eq.charAt(3)))) {
                return false;
            }
        }

        return true;
    }

    int find(int x) {
        if (x != parents[x]) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }

    public boolean equationsPossible_my(String[] equations) {
        if (equations.length == 1) {
            return true;
        }

        int[][] map = new int[26][26];

        for (String equation : equations) {
            char a = equation.charAt(0);
            char b = equation.charAt(equation.length() - 1);

            String operator = equation.substring(1, 3);

            if (operator.equals("==")) {
                if (map[a - 'a'][b - 'a'] == 0)   // unknow
                {
                    map[b - 'a'][a - 'a'] = 2;
                    map[a - 'a'][b - 'a'] = 2;
                } else if (map[a - 'a'][b - 'a'] == 1 || map[b - 'a'][a - 'a'] == 1)  // not equal
                {
                    return false;
                }

                for (int i = 0; i < 26; i++) {
                    if (map[a - 'a'][i] == 2) {
                        map[b - 'a'][i] = 2;
                    }

                    if (map[i][a - 'a'] == 2) {
                        map[i][b - 'a'] = 2;
                    }
                }
                for (int i = 0; i < 26; i++) {
                    if (map[b - 'a'][i] == 2) {
                        map[a - 'a'][i] = 2;
                    }
                    if (map[i][b - 'a'] == 2) {
                        map[i][a - 'a'] = 2;
                    }

                }

            } else if (operator.equals("!=")) {
                if (a == b)
                    return false;

                if (map[a - 'a'][b - 'a'] == 0)   // unknow
                {
                    map[b - 'a'][a - 'a'] = 1;
                    map[a - 'a'][b - 'a'] = 1;
                } else if (map[a - 'a'][b - 'a'] == 2 || map[b - 'a'][a - 'a'] == 2)  // equal
                {
                    return false;
                }

                for (int i = 0; i < 26; i++) {
                    if (map[a - 'a'][i] == 2) {
                        map[b - 'a'][i] = 1;
                    }

                    if (map[i][a - 'a'] == 2) {
                        map[i][b - 'a'] = 1;
                    }
                }
                for (int i = 0; i < 26; i++) {
                    if (map[b - 'a'][i] == 2) {
                        map[a - 'a'][i] = 1;
                    }
                    if (map[i][b - 'a'] == 2) {
                        map[i][a - 'a'] = 1;
                    }

                }
            }
        }

        return true;
    }
}
