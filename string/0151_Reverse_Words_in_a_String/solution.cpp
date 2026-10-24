/*
151. Reverse Words in a String

https://leetcode.com/problems/reverse-words-in-a-string/

*/
#include <string>
using namespace std;

/*
O(1) space and O(n) time c++
*/

class Solution
{
public:
  string reverseWords(string s)
  {
    string ans = "";
    int end = 0;

    while (end < s.size())
    {
      // removing space from start
      int start = getNonSpace(s, end);

      // if all of them are space
      if (start == s.size())
        break;

      // end with space or at the end
      end = getSpace(s, start);

      if (ans == "")
        ans = s.substr(start, end - start);
      else
        ans = s.substr(start, end - start) + " " + ans;
    }
    return ans;
  }

private:
  // get non space char index from i
  int getNonSpace(const string &s, int i)
  {
    for (; i < s.size(); i++)
    {
      if (s[i] != ' ')
        return i;
    }
    return i;
  }

  // get first space from i
  int getSpace(const string &s, int i)
  {
    for (; i < s.size(); i++)
    {
      if (s[i] == ' ')
        return i;
    }
    return i;
  }
};

#include <iostream>
#include <sstream>

class Solution2
{
public:
  void reverseWords(string &s)
  {
    istringstream is(s);
    string tmp;
    is >> s;
    while (is >> tmp)
      s = tmp + " " + s;
    if (s[0] == ' ')
      s = "";
  }
};