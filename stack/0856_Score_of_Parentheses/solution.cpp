/*
856. Score of Parentheses

https://leetcode.com/problems/score-of-parentheses/
*/
#include <string>
#include <climits>
#include <vector>

using namespace std;
/*
Recursion

Time complexity: O(n^2)

Space complexity: O(n)
*/
class Solution {
public:
  int scoreOfParentheses(string S) {
    return score(S, 0, S.length() - 1);
  }
private:
  int score(const string& S, int l, int r) {    
    if (r - l == 1) return 1; // "()"
    int b = 0;
    for (int i = l; i < r; ++i) {
      if (S[i] == '(') ++b;
      if (S[i] == ')') --b;
      if (b == 0) // balanced
        // score("(A)(B)") = score("(A)") + score("(B)")
        return score(S, l, i) + score(S, i + 1, r);    
    }
    // score("(A)") = 2 * score("A")
    return 2 * score(S, l + 1, r - 1); 
  }
};

/*
https://zxi.mytechroad.com/blog/string/leetcode-856-score-of-parentheses/

Solution2: Counting

Time complexity: O(n)
Space complexity: O(1)
*/
class Solution {
public:
  int scoreOfParentheses(string S) {
    int ans = 0;
    int d = -1;
    for (int i = 0; i < S.length(); ++i) {
      d += S[i] == '(' ? 1 : -1;
      if (S[i] == '(' && S[i + 1] == ')')
        ans += 1 << d;
    }
    return ans;
  }
};