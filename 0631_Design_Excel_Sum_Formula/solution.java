package cn.huang.leetcode;

import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

/*
631. Design Excel Sum Formula

 Your task is to design the basic function of Excel and implement the function of sum formula. Specifically, you need to implement the following functions:
Excel(int H, char W): This is the constructor. The inputs represents the height and width of the Excel form. H is a positive integer, range from 1 to 26. It represents the height. W is a character range from 'A' to 'Z'. It represents that the width is the number of characters from 'A' to W. The Excel form content is represented by a height * width 2D integer array C, it should be initialized to zero. You should assume that the first row of C starts from 1, and the first column of C starts from 'A'.

void Set(int row, char column, int val): Change the value at C(row, column) to be val.

int Get(int row, char column): Return the value at C(row, column).

int Sum(int row, char column, List of Strings : numbers): This function calculate and set the value at C(row, column), where the value should be the sum of cells represented by numbers. This function return the sum result at C(row, column). This sum formula should exist until this cell is overlapped by another value or another sum formula.
numbers is a list of strings that each string represent a cell or a range of cells. If the string represent a single cell, then it has the following format : ColRow. For example, "F7" represents the cell at (7, F).
If the string represent a range of cells, then it has the following format : ColRow1:ColRow2. The range will always be a rectangle, and ColRow1 represent the position of the top-left cell, and ColRow2 represents the position of the bottom-right cell.

Example 1:

Excel(3,"C");
// construct a 3*3 2D array with all zero.
//   A B C
// 1 0 0 0
// 2 0 0 0
// 3 0 0 0

Set(1, "A", 2);
// set C(1,"A") to be 2.
//   A B C
// 1 2 0 0
// 2 0 0 0
// 3 0 0 0

Sum(3, "C", ["A1", "A1:B2"]);
// set C(3,"C") to be the sum of value at C(1,"A") and the values sum of the rectangle range whose top-left cell is C(1,"A") and bottom-right cell is C(2,"B"). Return 4.
//   A B C
// 1 2 0 0
// 2 0 0 0
// 3 0 0 4

Set(2, "B", 2);
// set C(2,"B") to be 2. Note C(3, "C") should also be changed.
//   A B C
// 1 2 0 0
// 2 0 2 0
// 3 0 0 6

Note:

    You could assume that there won't be any circular sum reference. For example, A1 = sum(B1) and B1 = sum(A1).
    The test cases are using double-quotes to represent a character.
    Please remember to RESET your class variables declared in class Excel, as static/class variables are persisted across multiple test cases. Please see here for more details.

 */
public class LC_0631_DesignExcelSumFormula {

    class Excel {
        class Cell {
            int value;
            Map<String, Integer> children;

            Cell(int value, Map<String, Integer> children) {
                this.value = value;
                this.children = children;
            }
        }

        private Cell[][] form;
        private Stack<int[]> stack = new Stack<>();

        public Excel(int H, char W) {
            form = new Cell[H][W - 'A' + 1];
        }

        public void set(int r, char c, int v) {
            form[r - 1][c - 'A'] = new Cell(v, new HashMap<>());
            topologicalSort(r - 1, c - 'A');
            sumStack();
        }

        public int get(int r, char c) {
            if (form[r - 1][c - 'A'] == null) {
                return 0;
            }
            return form[r - 1][c - 'A'].value;
        }

        public int sum(int r, char c, String[] strs) {
            Map<String, Integer> range = convertToMap(strs);
            int sum = getSum(r - 1, c - 'A', range);
            set(r, c, sum);
            form[r - 1][c - 'A'] = new Cell(sum, range);

            return sum;
        }

        private void topologicalSort(int row, int col) {
            for (int i = 0; i < form.length; i++) {
                for (int j = 0; j < form[0].length; j++) {
                    if (form[i][j] != null && form[i][j].children.containsKey("" + (char)('A' + col) + (row + 1))) {
                        topologicalSort(i, j);
                    }
                }
            }
            stack.push(new int[]{ row, col });
        }

        private void sumStack() {
            while (!stack.isEmpty()) {
                int[] c = stack.pop();
                Cell cell = form[c[0]][c[1]];
                if (cell.children.size() > 0) {
                    getSum(c[0], c[1], cell.children);
                }
            }
        }

        private int getSum(int row, int col, Map<String, Integer> children) {
            int sum = 0;
            for (String s : children.keySet()) {
                int i = Integer.parseInt(s.substring(1)) - 1;
                int j = s.charAt(0) - 'A';
                sum += (form[i][j] == null ? 0 : form[i][j].value) * children.get(s);
            }
            form[row][col] = new Cell(sum, children);

            return sum;
        }

        private Map<String, Integer> convertToMap(String[] strs) {
            Map<String, Integer> map = new HashMap<>();
            for (String s : strs) {
                if (s.indexOf(":") < 0) {
                    map.put(s, map.getOrDefault(s, 0) + 1);
                } else {
                    String[] range = s.split(":");
                    int i1 = Integer.parseInt(range[0].substring(1));
                    int i2 = Integer.parseInt(range[1].substring(1));
                    char j1 = range[0].charAt(0);
                    char j2 = range[1].charAt(0);

                    for (int i = i1; i <= i2; i++) {
                        for (char j = j1; j <= j2; j++) {
                            String key = "" + j + i;
                            map.put(key, map.getOrDefault(key, 0) + 1);
                        }
                    }
                }
            }
            return map;
        }
    }
}
