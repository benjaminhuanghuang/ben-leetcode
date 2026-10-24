package cn.huang.leetcode;

import java.util.Stack;

/*
    682. Baseball Game

 */
public class LC_0682_BaseballGame {
    public int calPoints(String[] ops) {
        if (ops == null || ops.length == 0)
            return 0;

        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < ops.length; i++) {
            String op = ops[i];
            if (op.equals("C")) {
                stack.pop();
            } else if (op.equals("+")) {
                int score1 = stack.pop();
                int sum = score1 + stack.peek();
                stack.push(score1);
                stack.push(sum);
            } else if (op.equals("D")) {
                stack.push(2 * stack.peek());
            } else {
                stack.push(Integer.parseInt(op));
            }
        }
        int sum = 0;

        while (!stack.empty()) {
            sum += stack.pop();
        }
        return sum;
    }

    public int calPoints2(String[] ops) {
        Stack<Integer> history = new Stack<>();
        for (String op : ops) {
            switch (op) {
                case "+":
                    history.push(history.peek() + history.get(history.size() - 2));
                    break;
                case "D":
                    history.push(history.peek() * 2);
                    break;
                case "C":
                    history.pop();
                    break;
                default:
                    history.push(Integer.parseInt(op));
            }
        }
        int result = 0;
        for (int item : history) {
            result += item;
        }
        return result;
    }
}
