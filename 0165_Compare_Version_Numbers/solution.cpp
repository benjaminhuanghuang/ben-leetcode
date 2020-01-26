/*
165. Compare Version Numbers

https://leetcode.com/problems/compare-version-numbers/
*/
#include <string>
#include <sstream>

using namespace std;
/*
‘.’可能不止一个，可能有好多个，比如1.1.1.1.1.1.1
*/
class Solution
{
public:
  int compareVersion(string version1, string version2)
  {
    int n1 = version1.size(), n2 = version2.size();
    int i = 0, j = 0, d1 = 0, d2 = 0;
    while (i < n1 || j < n2)
    {
      while (i < n1 && version1[i] != '.')
      {
        d1 = d1 * 10 + version1[i++] - '0';
      }
      while (j < n2 && version2[j] != '.')
      {
        d2 = d2 * 10 + version2[j++] - '0';
      }
      if (d1 > d2)
        return 1;
      else if (d1 < d2)
        return -1;
      d1 = d2 = 0;
      ++i;
      ++j;
    }
    return 0;
  }
};

/*
Stream
*/
class Solution
{
public:
  int compareVersion(string version1, string version2)
  {
    istringstream v1(version1 + "."), v2(version2 + ".");
    int d1 = 0, d2 = 0;
    char dot = '.';
    while (v1.good() || v2.good())
    {
      if (v1.good())
        v1 >> d1 >> dot;
      if (v2.good())
        v2 >> d2 >> dot;
      if (d1 > d2)
        return 1;
      else if (d1 < d2)
        return -1;
      d1 = d2 = 0;
    }
    return 0;
  }
};