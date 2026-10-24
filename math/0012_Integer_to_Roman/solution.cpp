/*
  12. Integer to Roman

  https://leetcode.com/problems/integer-to-roman/
*/
#include <string>
#include <vector>

using namespace std;

/*
https://zxi.mytechroad.com/blog/simulation/leetcode-12-integer-to-roman/
Map integer 1,4,5,9,10,40,50,90, …, 1000 to Romain

Start from the largest number y,

if x >= y:
ans += Roman[y]
x -= y

Time complexity: O(x)

Space complexity: O(x)
*/
class Solution
{
public:
  string intToRoman(int num)
  {
    vector<pair<int, string>> v{
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

    string ans;
    auto it = cbegin(v);
    while (num)
    {
      if (num >= it->first)
      {
        num -= it->first;
        ans += it->second;
      }
      else
      {
        ++it;
      }
    }
    return ans;
  }
};

class Solution
{
public:
  string intToRoman(int num)
  {
    vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> strs = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string ans;

    for (int i = 0; i < values.size(); i++)
    {
      while (num >= values[i])
      {
        num -= values[i];
        ans.append(strs[i]);
      }
    }
    return ans;
  }
};