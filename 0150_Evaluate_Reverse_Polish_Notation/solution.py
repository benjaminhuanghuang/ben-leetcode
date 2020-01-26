'''
150. Evaluate Reverse Polish Notation [easy][mastered]

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6


'''


class Solution(object):
    # Passed at second try!
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        stack = []
        for t in tokens:
            if t in ["+", "-", "*", "/"]:
                operand2 = stack.pop()
                operand1 = stack.pop()
                if t == "/":
                    # result = operand1 / operand2
                    result = operand1 / operand2 if operand1 * operand2 >= 0 else \
                        -(abs(operand1) / abs(operand2))  # -3 /2 in python is -2
                elif t == "*":
                    result = operand1 * operand2
                elif t == "+":
                    result = operand1 + operand2
                else:  # t == "-":
                    result = operand1 - operand2

                stack.append(result)
            else:
                stack.append(int(t))
        return stack[-1]


input = ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
s = Solution()
print s.evalRPN(input)
