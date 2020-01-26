/*
3. Longest Substring Without Repeating Characters []

https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

#include <string>
#include <vector>
#include <climits>

using namespace std;
/*

Solution: HashTable + Sliding Window
Using a hashtable to remember the last index of every char.  And keep tracking the starting point of a valid substring.
start = max(start, last[s[i]] + 1)
ans = max(ans, i – start + 1)

Time complexity: O(n)
Space complexity: O(128)
*/
class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    int n = s.length();
    int start = 0;
    vector<int> lastOccurred(128, INT_MIN);
    int maxLength = 0;

    for (int i = 0; i < n; ++i)
    {
      if (lastOccurred[s[i]] != INT_MIN) // this char is already presented
      {
        // lastOccurrd[ch] 不存在, or < start -> 无需操作
        // lastOccurrd[ch] >= start -> Update start
        start = max(start, lastOccurred[s[i]] + 1);  // set start to max(start, lastOccurred[s[i]] + 1)
      }
      maxLength = max(maxLength, i - start + 1); // if char is not presented, start is 0
      lastOccurred[s[i]] = i;
    }

    return maxLength;
  }
};