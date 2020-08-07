#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <set>
#include <utility>
#include <numeric>
using namespace std;

int getHeight(int label)
{
  int h = 0;
  while (label > 0)
  {
    label = label >> 1;
    h++;
  }
  return h;
}
vector<int> pathInZigZagTree(int label)
{
  vector<int> ans;
  while (label)
  {
    ans.push_back(label);
    int h = getHeight(label) - 1;
    int prev = ((1 << h) + (1 << (h + 1)) - 1 - label) / 2;
    label = prev;
  }
  return {end(ans), begin(ans)};
}

int main()
{
  auto ans = pathInZigZagTree(14);
  cout << ans.size() << endl;
  return 0;
}