#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <utility>

using namespace std;
/*
5440. XOR Operation in an Array
*/
int xorOperation(int n, int start)
{
  int ans = 0;

  for (int i = 0; i < n; i++)
  {
    ans ^= start + 2 * i;
  }
  return ans;
}

/*
5441. Making File Names Unique
*/
vector<string> getFolderNames(vector<string> &names)
{
  unordered_map<string, int> counter;
  unordered_set<string> usedName;
  vector<string> folders;

  for (string name : names)
  {
    int count = counter[name]++;
    string folerName = count > 0 ? name + "(" + to_string(count) + ")" : name;
    while (usedName.count(folerName))
    {
      count++;
      folerName = name + "(" + to_string(count) + ")";
    }
    folders.push_back(folerName);
    usedName.insert(folerName);
  }
  return folders;
}

/*
5442. Avoid Flood in The City

After that, it will rain over lakes [1,2]. It's easy to prove that no matter 
which lake you choose to dry in the 3rd day, the other one will flood.

*/
int arrangeCoins(int n)
{
  int l = 1;
  int r = n;
  while (l <= r)
  {
    // Returns the smallest m in range [l, r] such that g(m) is true.
    int m = l + (r - l) / 2;
    long total = m * (m + 1) / 2;
    if (total >= n)
    {
      r = m - 1;
    }
    else
    {
      l = m + 1;
    }
  }
  return l;
}

bool canInput(string word)
{
  vector<string> rows = {
      "qwertyuiopQWERTYUIOP",
      "asdfghjklASDFGHJKL",
      "zxcvbnmZXCVBNM"};

  int row = 0;

  for (int i = 0; i < rows.size(); i++)
  {
    if (find(rows[i].begin(), rows[i].end(), word[0]) != rows[i].end())
    {
      row = i;
      break;
    }
  }

  for (char c : word)
  {
    if (rows[row].find(c) == std::string::npos)
    {
      return false;
    }
  }

  return true;
}

int main()
{
  // vector<vector<int>> a= {{21799},{64145},{88382},{60483}};
  // vector<string> input = {"gta", "gta(1)", "gta", "avalon"};
  // vector<int> input{1,2,0,0,2,1};//{10,20,20};//{69, 0, 0, 0, 69};

  // auto ans = avoidFlood(input);
  // for (auto i : ans)
  // {
  //   cout << i << endl;
  // }
  // int ans = arrangeCoins(5);
  auto ans = canInput("Hello");
  cout << ans;
}
