/*
804. Unique Morse Code Words
https://leetcode.com/problems/unique-morse-code-words/
*/
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  int uniqueMorseRepresentations(vector<string> &words)
  {
    vector<string> m{".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    unordered_set<string> s;
    for (const string &word : words)
    {
      string code;
      for (char c : word)
        code += m[c - 'a'];
      s.insert(code);
    }
    return s.size();
  }
};