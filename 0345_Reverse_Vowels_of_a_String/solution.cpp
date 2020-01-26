/*
345. Reverse Vowels of a String

https://leetcode.com/problems/reverse-vowels-of-a-string/
*/
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  string reverseVowels(string s)
  {
    int l = 0;
    int r = s.size() - 1;
    while (l < r)
    {
      while (!isVowel(s[l]) && l < r)
        ++l;
      while (!isVowel(s[r]) && l < r)
        --r;
      swap(s[l++], s[r--]);
    }
    return s;
  }

private:
  bool isVowel(char c)
  {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
};