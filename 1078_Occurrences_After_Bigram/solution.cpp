#include <vector>
#include <sstream>
#include <string>

using namespace std;
/*
  C++没有split()函数，一个可以替换的方案是使用stringstream 和 getline 实现字符串按空格分割。
*/
class Solution
{
public:
  vector<string> findOcurrences(string text, string first, string second)
  {
    vector<string> ans;
    stringstream ss(text);
    string w1, w2, w3;
    while (ss >> w3)
    {
      if (w1 == first && w2 == second)
        ans.push_back(w3);
      w1 = w2;
      w2 = w3;
    }
    return ans;
  }
};