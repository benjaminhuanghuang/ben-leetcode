/*
1108. Defanging an IP Address

https://leetcode.com/problems/defanging-an-ip-address/
 
Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".


Example 1:

Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"

*/
#include <string>

using namespace std;
/*
    My Solution
 */
class Solution
{
public:
  string defangIPaddr(string address)
  {
    string ans;
    for (char c : address)
    {
      if (c == '.')
        ans += "[.]";
      else
        ans += '.';
    }

    return ans;
  }
};

class Solution_Inplace
{
public:
  string defangIPaddr(string address)
  {
    for (int i = 0; i < address.size(); i++)
    {
      if (address[i] == '.') //if '.' is found in the string, it will be erased and replaced with "[.]"
      {
        address.erase(address.begin() + i);
        address.insert(i, "[.]");
        i = i + 2; //i is incremented since we are adding two more characters
      }
    }
    return address;
  }
};