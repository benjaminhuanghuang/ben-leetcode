/*
76. Minimum Window Substring


https://leetcode.com/problems/minimum-window-substring/
 */

#include <string>
#include <vector>
#include <climits>

using namespace std;
/*
    // Sliding window，尾指针不断往后扫，当扫到有一个窗口包含了所有T的字符，然后再收缩头指针，直到不能再收缩为止。
    // 最后记录所有可能的情况中窗口最小的。
    // 用dict来表示滑窗， 字符加入滑窗，从dict[c] - 1，从滑窗中删去字符，dict[c] +1

    https://www.youtube.com/watch?v=dzdtzymjM7A
 */
/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var minWindow = function(s, t)
{
  const dict = new Array(128).fill(0);
  for (let i = 0; i < t.length; i++)
  {
    dict[t.charCodeAt(i)]++;
  }

  let start = 0;
  let restChartCount = t.length;
  let minLength = s.length + 1;
  let res = "";

  for (let i = 0; i < s.length; i++)
  {
    if (dict[s.charCodeAt(i)] > 0)
    {
      // if s[i] is char in t string
      restChartCount--;
    }
    dict[s.charCodeAt(i)]--; // 在s中且不在t中的的字符的count会变为负值

    while (restChartCount == 0) //When restChartCount == 0, substring S[start : i] contains string T
    {

      if (minLength > i - start + 1) // find res shorter than last res or find res firstly
      {

        minLength = i - start + 1;
        res = s.substring(start, start + minLength);
      }

      if (++dict[s.charCodeAt(start)] > 0)
      {
        //++dict[s.charAt(start)] > 0 说明这是t中的字符，
        //  remove first char from the sub string
        restChartCount++;
      }
      start++;
    }
  }
  return res;
};