/*
833. Find And Replace in String
https://leetcode.com/problems/find-and-replace-in-string/

给了原始的字符串S，给出了要开始替换的位置indexes，判断S在indexes的位置向后是否能匹配sources中对应位置的元素，如果相等，则把S的该部分替换成targets对应的部分。
*/
#include <vector>
#include <string>

using namespace std;

/*
https://www.cnblogs.com/grandyang/p/10352323.html
不可能直接对S进行替换操作的，因为那样直接改变了S的值和长度，影响以后的匹配操作。
新建了一个保存pair对儿的数组，将indexes数组中的数字跟其位置坐标组成pair对儿
*/
class Solution
{
public:
  string findReplaceString(string S, vector<int> &indexes, vector<string> &sources, vector<string> &targets)
  {
    vector<pair<int, int>> v;
    for (int i = 0; i < indexes.size(); ++i)
    {
      v.push_back({indexes[i], i});   // position: index
    }
    sort(v.rbegin(), v.rend());  //大到小的方式排序
    
    for (auto a : v)
    {
      int pos = a.first;
      string s = sources[a.second], t = targets[a.second];
      if (S.substr(pos, s.size()) == s)
      {
        S = S.substr(0, pos) + t + S.substr(pos + s.size());   // replace
      }
    }
    return S;
  }
};