#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> buildArray(vector<int> &target, int n)
{
  vector<string> arr;
  int i = 0;
  int num = 1;
  while (num <= n && i < target.size())
  {
    while (num < target[i] )
    {
      arr.push_back("Push");
      arr.push_back("Pop");
      num++;
    }
    //
    arr.push_back("Push");
    i++;
    num++;
  }
  return arr;
}


int maxScore(string s)
  {
    int count_1 = std::count_if(s.begin(), s.end(), [](char c) { return c == '1'; });
    int res = 0;
    int count_1_left = 0;
    int count_0_left = 0;
    for (auto it = s.begin(); it != s.end(); ++it)
    {
      if (*it == '0')
        count_0_left += 1;
      else
        count_1_left += 1;

      res = max(res, count_0_left + count_1 - count_1_left, 0);
    }
    return res;
  }

int main()
{
  cout << maxScore("00")<<endl;
}

