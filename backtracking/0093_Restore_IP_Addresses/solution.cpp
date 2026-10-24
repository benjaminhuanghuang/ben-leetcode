
/*
93. Restore IP Addresses

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]


https://leetcode.com/problems/restore-ip-addresses/

*/
#include <vector>
#include <string>

using namespace std;

/*
    https://www.youtube.com/watch?v=pi-S2TLYuL4

    time: O(3^4)=>O(1)  space: O(n)
     */
class Solution
{
public:
  vector<string> restoreIpAddresses(string s)
  {
    vector<string> ans;
    string curr;
    dfs(s, 0, 0, curr, ans);
    return ans;
  }

private:
  void dfs(string &s, int count, int start, string curr, vector<string> &ans)
  {
    if (count > 4)
    {
      return;
    }
    if (count == 4 && start == s.length())
    {
      ans.push_back(curr);
      return;
    }

    for (int i = 1; i < 4; i++)
    { //  取 1位，2位，3位
      if (start + i > s.length())
        break;

      string tmp = s.substr(start, start + i);
      if ((tmp[0] == '0' && tmp.length() > 1) || (i == 3 && stoi(tmp) >= 256))
        continue;
      dfs(s, count + 1, start + i, curr + tmp + (count == 3 ? "" : ".") , ans);
    }
  }
};