/*
468. Validate IP Address

https://leetcode.com/problems/validate-ip-address/
*/
#include <string>

using namespace std;

class Solution
{
public:
  string validIPAddress(string IP)
  {
    bool isIPv4 = true;
    bool isIPv6 = true;
    string cur;
    int seg = 0;
    for (char c : IP)
    {
      if (c == '.')
      {
        ++seg;
        isIPv6 = false;
        isIPv4 &= isV4Num(cur);
        cur.clear();
      }
      else if (c == ':')
      {
        ++seg;
        isIPv4 = false;
        isIPv6 &= isV6Num(cur);
        cur.clear();
      }
      else
        cur += c;
    }
    isIPv4 &= isV4Num(cur) && seg == 3;
    isIPv6 &= isV6Num(cur) && seg == 7;

    return isIPv4 ? "IPv4" : (isIPv6 ? "IPv6" : "Neither");
  }

private:
  bool isV4Num(string n)
  {
    if (n.length() > 3 || n.empty())
      return false;
    std::reverse(n.begin(), n.end());
    int a = 0;
    int f = 1;
    for (char c : n)
    {
      if (!isdigit(c))
        return false;
      if (c == '0' && f > 1)
        return false;
      a += (c - '0') * f;
      f *= 10;
    }
    return a >= 0 && a <= 255;
  }

  bool isV6Num(string n)
  {
    if (n.length() > 4 || n.empty())
      return false;
    std::reverse(n.begin(), n.end());

    int a = 0;
    int f = 1;
    for (char c : n)
    {
      if (isdigit(c))
        a += (c - '0') * f;
      else if (c >= 'a' && c <= 'f' || c >= 'A' && c <= 'Z')
        a += (tolower(c) - 'a' + 10) * f;
      else
        return false;
      f *= 16;
    }

    return a >= 0 && a < (1 << 16);
  }
};
