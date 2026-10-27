/*
443. String Compression

https://leetcode.com/problems/string-compression/

Follow up:
Could you solve it using only O(1) extra space?

*/
#include <vector>
#include <string>

using namespace std;
/*
  Two points
  p: 压缩部分   i: go through
*/
class Solution
{
public:
  int compress(vector<char> &chars)
  {
    const int n = chars.size();
    int p = 0;
    for (int i = 1; i <= n; ++i)
    {
      int count = 1;
      while (i < n && chars[i] == chars[i - 1])
      {
        ++i;
        ++count;
      }
      chars[p++] = chars[i - 1]; // chars[p] = chars[i - 1], then p = p+1
      if (count == 1)
        continue;
      for (char c : to_string(count))
        chars[p++] = c;
    }
    return p;
  }
};