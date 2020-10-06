/*
686. Repeated String Match

https://leetcode.com/problems/repeated-string-match/
*/
#include <string>
using namespace std;

/*
当A重复一定次数后，长度比B长了，那么就可以停止了！
因为如果这种情况下B都不是A的子串，那么循环再多也没用。
因为对于B来说，A所有可能的重复都已经出现了。
*/
class Solution
{
public:
  int repeatedStringMatch(string A, string B)
  {
    int lenA = A.size(), lenB = B.size();
    int times = lenB / lenA + 3;
    string t = A;
    for (int i = 1; i < times; i++)
    {
      if (t.find(B) != string::npos)
        return i;
      t += A;
    }
    return -1;
  }
};

class Solution
{
public:
  int repeatedStringMatch(string A, string B)
  {
    string t;
    int count = 0;
    while (t.size() < B.size())
    {
      t += A;
      count++;
    }

    if (t.find(B) != string::npos)
    {
      return count;
    }
    
    t.append(A);
    count++;
    if (t.find(B) != string::npos)
    {
      return count;
    }
    return -1;
  }
};