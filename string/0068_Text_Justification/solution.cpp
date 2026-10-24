/*
68. Text Justification

https://leetcode.com/problems/text-justification/
 */
#include <string>
#include <vector>

using namespace std;
/*
  单词排成行, 尽量均匀插入空格，最后用空格填充
 */
class Solution
{
public:
  vector<string> fullJustify(vector<string> &words, int maxWidth)
  {
    vector<string> res;
    int wordIdx = 0;

    while (wordIdx < words.size())
    {
      int count = words[wordIdx].length();
      int lastWord = wordIdx + 1; // index of the last word can be put in current line
      while (lastWord < words.size())
      {
        if (words[lastWord].length() + count + 1 > maxWidth) // + 1 is the space
          break;
        count += 1 + words[lastWord].length();
        lastWord++;
      }
      string textLine;
      textLine += words[wordIdx];
      int diff = lastWord - wordIdx - 1; // how many gap between words in line
      if (lastWord == words.size() || diff == 0)
      {
        for (int i = wordIdx + 1; i < lastWord; i++)
        {
          textLine += " ";
          textLine += words[i];
        }
        for (int i = textLine.length(); i < maxWidth; i++)
        {
          textLine += " ";
        }
      }
      else
      {
        int spaces = (maxWidth - count) / diff;
        /*
        If the number of spaces on a line do not divide evenly between words, the empty slots on the left will
        be assigned more spaces than the slots on the right.
          */
        int r = (maxWidth - count) % diff;
        for (int i = wordIdx + 1; i < lastWord; i++)
        {
          for (int k = spaces; k > 0; k--)
          {
            textLine += " ";
          }
          if (r > 0)
          {
            textLine += " ";
            r--;
          }
          textLine += " ";
          textLine += words[i];
        }
      }
      res.push_back(textLine);
      wordIdx = lastWord;
    }

    return res;
  }
};