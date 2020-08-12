/*
76. Minimum Window Substring


https://leetcode.com/problems/minimum-window-substring/
 */

#include <string>
#include <vector>

using namespace std;
/*
    // Sliding window，尾指针不断往后扫，当扫到有一个窗口包含了所有T的字符，然后再收缩头指针，直到不能再收缩为止。
    // 最后记录所有可能的情况中窗口最小的。
    // 用dict来表示滑窗， 字符加入滑窗，从dict[c] - 1，从滑窗中删去字符，dict[c] +1

    https://www.youtube.com/watch?v=dzdtzymjM7A
 */
class Solution
{
public:
  string minWindow(string s, string t)
  {
    vector<int> dict(128);
    for (char c : t)
    {
      dict[c]++;
    }

    int start = 0;
    int restChartCount = t.length();
    int min = INT_MAX;
    string res = "";

    for (int i = 0; i < s.length(); i++)
    {
      if (dict[s[i]] > 0)
      {
        // if s[i] is char in t string
        restChartCount--;
      }
      dict[s[i]]--; // 在s中且不在t中的的字符的count会变为负值

      while (restChartCount == 0) //When restChartCount == 0, substring S[start : i] contains string T
      {
        if (min > i - start + 1) // find res shorter than last res or find res firstly
        {
          min = i - start + 1;
          res = s.substr(start, min);
        }

        if (++dict[s[start]] > 0)
        {
          //++dict[s.charAt(start)] > 0 说明这是t中的字符，
          //  remove first char from the sub string
          restChartCount++;
        }
        start++;
      }
    }
    return res;
  }
};