#include <string>
using namespace std;

/*

*/
class Solution
{
public:
  string reverseStr(string s, int k)
  {
    const int n = s.length();
    for (int i = 0; i <= n / k; i += 2)
      std::reverse(s.begin() + i * k, s.begin() + min(n, (i + 1) * k));   // min() is important
    return s;
  }
};