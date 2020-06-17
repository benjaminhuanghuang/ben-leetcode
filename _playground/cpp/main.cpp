#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_set>

using namespace std;

string reformat(string s)
{
  string letters;
  string digits;

  for (char c : s)
  {
    if (isdigit(c))
    {
      digits += c;
    }
    else
    {
      letters += c;
    }
  }
  if (abs((int)letters.length() - (int)digits.length()) > 1)
  {
    return "";
  }
  string formatted;
  auto letterIt = letters.begin();
  auto digitIt = digits.begin();

  if (letters.size() > digits.size())
  {
    for (int i = 0; i < digits.size(); i++)
    {
      formatted += *(letterIt++);
      formatted += *(digitIt++);
    }
    formatted += *(letterIt++);
  }
  else
  {
    for (int i = 0; i < letters.size(); i++)
    {
      formatted += *(digitIt++);
      formatted += *(letterIt++);
    }
    if (digits.size() > letters.size())
      formatted += *(digitIt++);
  }

  return formatted;
}
int main()
{
  cout << reformat("0aa") << endl;
}
