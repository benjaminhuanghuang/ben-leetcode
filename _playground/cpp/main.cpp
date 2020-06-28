#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <utility>
#include <numeric>

using namespace std;
bool isPathCrossing(string path)
{

  set<pair<int, int>> posSet;
  posSet.insert(pair<int, int>{0, 0});
  int x = 0;
  int y = 0;
  for (char c : path)
  {
    if (c == 'N')
    {
      y++;
    }
    else if (c == 'S')
    {
      y--;
    }
    else if (c == 'E')
    {
      x++;
    }
    else if (c == 'W')
    {
      x--;
    }
    pair<int,int> pos = pair<int,int>(x,y);
    if(posSet.count(pos))
    {
      return true;
    }
    posSet.insert(pos);
  }

  return false;
}

bool canArrange(vector<int>& arr, int k) {
  int sum = accumulate(arr.begin(), arr.end(), 0);

  return sum % k == 0;



}


int numSubseq(vector<int>& nums, int target) {
  sort(nums.begin(), nums.end());

  int sum = 0;
  int i =0;
  for(;i < nums.size(); i++)
  {
      sum += nums[i];
      if(sum >= target)
      {
        break;
      }
  }
  return 
}



int main()
{
  //vector<int> input = {2, 0, 6, 6};
  auto ans = isPathCrossing("NESWW");
  cout << ans << endl;
}
