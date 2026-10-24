/*
71. Simplify Path
https://leetcode.com/problems/simplify-path/
*/

#include <string>
#include <vector>
#include <sstream>

using namespace std;

/*
 Java code:
 String[] tokens = path.split("/");

*/
class Solution
{
public:
  string simplifyPath(string path)
  {
    vector<string> v;
    int i = 0;
    while (i < path.size())
    {
      while (path[i] == '/' && i < path.size())
        ++i;
      if (i == path.size())
        break;
      int start = i;
      while (path[i] != '/' && i < path.size())
        ++i;
      int end = i - 1;
      string s = path.substr(start, end - start + 1);
      if (s == "..")
      {
        if (!v.empty())
          v.pop_back();
      }
      else if (s != ".")
      {
        v.push_back(s);
      }
    }
    if (v.empty())
      return "/";
    string res;
    for (int i = 0; i < v.size(); ++i)
    {
      res += '/' + v[i];
    }
    return res;
  }
};

/*
Using stream
*/
class Solution
{
public:
  string simplifyPath(string path)
  {
    string res, token;
    stringstream ss(path);
    vector<string> v;
    while (getline(ss, token, '/'))
    {
      if (token == "" || token == ".")
        continue;
      if (token == ".." && !v.empty())
        v.pop_back();
      else if (token != "..")
        v.push_back(token);
    }
    for (string s : v)
      res += "/" + s;
    return res.empty() ? "/" : res;
  }
};