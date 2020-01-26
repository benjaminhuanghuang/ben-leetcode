/*
551. Student Attendance Record I

https://leetcode.com/problems/student-attendance-record-i/
*/
#include <string>
#include <regex>
using namespace std;

class Solution
{
public:
  bool checkRecord(string s)
  {
    int a{0};
    int l{0};
    for (char c : s)
    {
      if (c == 'A')
        ++a;
      if (c == 'L')
        ++l;
      else
        l = 0;
      if (a > 1 || l > 2)
        return false;
    }
    return true;
  }
};

/*
https://zxi.mytechroad.com/blog/string/leetcode-551-student-attendance-record-i/
Regex
*/
class Solution {
public:
  bool checkRecord(string s) {
    return !std::regex_search(s, std::regex("A.*A|LLL"));
  }
};