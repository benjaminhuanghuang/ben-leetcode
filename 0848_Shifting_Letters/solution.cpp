/*
848. Shifting Letters

https://leetcode.com/problems/shifting-letters/
*/
#include <string>
#include <vector>
using namespace std;

/*
  给出了一个字符串S，以及和这个字符串等长的数组shifts。定义了一个shift操作：把某个字符在字母表上移动某位（字母’z’再向右移得到’a’）。
  现在遍历shifts，每个操作都是把"当前位数之前的所有字符"移动shift位。求最后得到的字符串。

  如果普通的遍历，在每次遍历的时候再把之前所有shift过的再次shift，那么就会超时。

  所以正确的做法是先求出每个字符串需要shift的次数。即对shifts进行位置之后的求和。得出要shift的位数之后，按照题目给的那种循环去操作就好了。
*/

/*
http://zxi.mytechroad.com/blog/string/leetcode-848-shifting-letters/
*/
class Solution
{
public:
  string shiftingLetters(string S, vector<int> &shifts)
  {
    int c = 0;
    for (int i = shifts.size() - 1; i >= 0; --i)
    {
      c += (shifts[i] % 26);
      S[i] = (S[i] - 'a' + c) % 26 + 'a';
    }
    return S;
  }
};