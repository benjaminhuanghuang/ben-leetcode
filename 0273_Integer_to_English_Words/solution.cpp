/*
273. Integer to English Words
 https://leetcode.com/problems/integer-to-english-words/

 */

#include <string>
using namespace std;

static const string postfix[]{"", " Thousand", " Million", " Billion"};
static const string num0To9[]{"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
static const string num10To19[]{"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
static const string num10To90[]{"Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

class Solution
{

public:
  string numberToWords(int num)
  {
    if (num == 0)
      return "Zero";
    string res = "";
    int postfixIndex = 0;

    while (num > 0)
    {
      string group = "";    // process 3 digit as group
      int cur = num % 1000; //process the last 3 digits
      string numberPart = convert(cur);
      if (numberPart == "")
        group = "";
      else
        group = numberPart + postfix[postfixIndex];

      //res[0] == ' ' happens when previous(lower) group is ""
      if (res.length() != 0 && res[0] != ' ')
        res = group + " " + res;
      else
      {
        res = group + res;
      }
      num = num / 1000; //drop 3 digits
      postfixIndex++;
    }
    return res;
  }

  // convert number < 1000
  string convert(int num)
  {
    if (num == 0)
      return "";

    if (num < 10)
      return num0To9[num];
    else if (num >= 10 && num <= 19)
      return num10To19[num - 10];
    else if (num >= 20 && num <= 99)
    {
      if (num % 10 == 0)
        return num10To90[num / 10 - 1];
      else
      {
        string s1 = num0To9[num % 10];
        string s2 = num10To90[num / 10 - 1];
        return s2 + "-" + s1;
      }
    }
    else
    {
      if (num % 100 == 0)
        return num0To9[num / 100] + " Hundred";
      else
      {
        string temp = convert(num % 100);
        return convert(num - num % 100) + " " + temp;
      }
    }
  }
};