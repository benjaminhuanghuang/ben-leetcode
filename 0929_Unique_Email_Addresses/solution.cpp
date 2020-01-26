/*
929. Unique Email Addresses

https://leetcode.com/problems/unique-email-addresses/
*/
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

/*
域名部分不用管，只管用户名部分，用户名中如果包含有'.'，那么把这个'.'给去掉；如果用户名中有'+'，那么把加号以及后面的用户名部分全部去掉。
*/
class Solution
{
public:
  int numUniqueEmails(vector<string> &emails)
  {
    unordered_set<string> s;
    for (const string &email : emails)
    {
      string e;
      bool at = false;
      bool plus = false;
      for (char c : email)
      {
        if (c == '.')
        {
          if (!at)
            continue;
        }
        else if (c == '@')
        {
          at = true;
        }
        else if (c == '+')
        {
          if (!at)
          {
            plus = true;
            continue;
          }
        }
        if (!at && plus)
          continue;
        e += c;
      }
      s.insert(std::move(e));
    }
    return s.size();
  }
};