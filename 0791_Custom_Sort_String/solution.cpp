/*
791. Custom Sort String

https://leetcode.com/problems/custom-sort-string/

S是一个自定义的字母表顺序，现在要把T中的字符按照S的顺序进行排序。如果T中有S中不存在的字符，那么可以处在结果的任何位置。
*/
#include <string>
#include <unordered_map>

using namespace std;
/*
使用字典保存T中的每个字母出现的次数，然后遍历S中的每个字符，查表构建新的结果字符串，并且把已经遍历了的字符的次数设为0。
最后把count中剩余的字符放到最后。

这里用到了一个技巧，Counter中使用不存在的索引会返回0.
*/
class Solution
{
public:
  string customSortString(string S, string T)
  {
    unordered_map<char, int> dic;
    // count the char in T
    for (char c : T)
      dic[c]++;
      
    string res;
    // using the order of S
    for (char c : S)
    {
      for (int i = 0; i < dic[c]; i++)
      {
        res += c;
      }
      dic[c] = 0; // clear
    }
    for (auto kv : dic)
    {
      if (kv.second)
      {
        for (int i = 0; i < kv.second; i++)
        {
          res += kv.first;   // append the char not in S
        }
      }
    }
    return res;
  }
};