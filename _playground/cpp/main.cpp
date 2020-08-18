#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <set>
#include <utility>
#include <numeric>
using namespace std;

int maxFreq(string s, int maxLetters, int minSize, int maxSize)
{
  int ans = 0;
  unordered_set<char> Set;

  int start = 0;
  int end = 0;

  while (end < s.size())
  {
    while (end - start + 1 < minSize && end < s.size() && Set.size() <= maxLetters)
    {
      end++;
      Set.insert(s[end]);
    }

    if (end - start + 1 <= maxSize)
    {
      ans++;
    }

    Set.erase(s[start]);
    start++;
  }
  return ans;
}

int main()
{
  auto result = maxFreq("aababcaab", 2, 3,4);
  return 0;
}