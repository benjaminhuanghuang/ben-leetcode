/*
722. Remove Comments

https://leetcode.com/problems/remove-comments/
*/
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  vector<string> removeComments(vector<string> &source)
  {
    vector<string> res;
    bool blocked = false;
    string codeline = "";
    for (string line : source)
    {
      for (int i = 0; i < line.size(); ++i)
      {
        if (!blocked)
        {
          if (i == line.size() - 1)
            codeline += line[i];
          else
          {
            string t = line.substr(i, 2);
            if (t == "/*")
            {
              blocked = true;
              ++i;
            }
            else if (t == "//")
              break;
            else
              codeline += line[i];
          }
        }
        else
        {
          if (i < line.size() - 1)
          {
            string t = line.substr(i, 2);
            if (t == "*/")
              blocked = false, ++i;
          }
        }
      }
      if (!codeline.empty() && !blocked)
      {
        res.push_back(codeline);
        codeline = "";
      }
    }
    return res;
  }
};