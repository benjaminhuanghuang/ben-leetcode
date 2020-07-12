#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <set>
#include <utility>
#include <numeric>
using namespace std;

int main()
{
  /* Enter your code here.  */
  // int n;
  // cin >> n;
  // int nums[n];

  // for (int i = 0; i < n; i++)
  // {
  //   cin >> nums[i];
  // }

  int n = 5;
  int nums[5] = {1, 5, 3, 8, 2};
  int count = 0;
  bool sorted = false;

  while (!sorted)
  {
    count++;
    sorted = true;
    for (int i = 0; i < n - 1; i++)
    {
      if (nums[i] > nums[i + 1])
      {
        swap(nums[i], nums[i + 1]);
        sorted = false;
      }
    }
  }
  for (int i = 0; i < n; i++)
    cout << nums[i] << endl;
  // cout << count << endl;
  return 0;
}