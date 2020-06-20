#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_set>

using namespace std;

int getDigits(int num)
{
  int digits = 0;
  while (num > 0)
  {
    num = num / 10;
    digits++;
  }
  return digits;
}

int findNumbers(vector<int> &nums)
{
  int count = 0;
  for (int i : nums)
  {
    if ((getDigits(i) & 1) == 0)
    {
      count++;
    }
  }
  return count;
}

int main()
{
  // vector<vector<int>> a= {{21799},{64145},{88382},{60483}};
  vector<int> input = {12, 345, 2, 6, 7896};
  auto ans = findNumbers(input);
  cout << ans << endl;
}
