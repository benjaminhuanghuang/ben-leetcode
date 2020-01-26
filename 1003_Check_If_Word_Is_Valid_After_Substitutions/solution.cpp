/*
1003. Check If Word Is Valid After Substitutions [Medium]

https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/
*/

#include <vector>
#include <string>
#include <stack>

using namespace std;

/*
每次都去插入一个"abc"字符串，那么到最后一步一定会有"abc"。所以如果倒着来，每次把"abc"进行替换成""，
那么一定能回到最初的状态，也就是空字符串。

遍历S:
1) 当遇到'a'或'b'时，用一个栈stk来存储
2) 当遇到'c'时，pop栈中的元素，看能否依次pop出'b'和'c'，如果不能则返回false
遍历结束后，如果stk为空，则返回true，不然为false
*/

/*
  https://zxi.mytechroad.com/blog/uncategorized/leetcode-1003-check-if-word-is-valid-after-substitutions/

  Solution: 
  If current char can be appended to the stack do so, if the top of stack is “abc” pop, otherwise push the 
  current char to the stack. Check whether the stack is empty after all chars were processed.

  Time complexity: O(n)
  Space complexity: O(n)
*/

class Solution {
public:
  bool isValid(string S) {
    stack<string> st;
    for (char ch : S) {
      if (st.empty()) {
        st.push("");
      }
      string& s = st.top();
      char exp = 'a' + s.length();
      if (ch == exp) {
        s += ch;
        if (s == "abc") st.pop();
      } else if (ch != 'a'){
        return false;        
      } else {
        st.push("a");
      }
    }
    return st.empty();
  }
};
/*
用一个stack，遇到a入栈，遇到b判断现在是否有一个a在栈顶，遇到c判断现在栈顶是否有a和b， 其他情况都是非法的
*/
class Solution {
public:
  bool isValid(string S) {
    stack<char> stack;
    for(char ch: S) {
        if(ch == 'a') {
            stack.push(ch);
        }
        else if(ch == 'b') {
            if(stack.empty() || stack.top() != 'a') {
                return false;
            }
            stack.push(ch);
        }
        else { // ch == 'c'
            if(stack.empty() || stack.top() != 'b') {
                return false;
            }
            stack.pop(); // pop b
            if(stack.empty() || stack.top() != 'a') {
                return false;
            }
            stack.pop(); // pop a
        }
    }
    return stack.empty();
  }
};