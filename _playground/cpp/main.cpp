#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_set>

using namespace std;

vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
  {
    vector<pair<int, int>> counts; // index, count
    for (int i = 0; i < mat.size(); i++)
    {
      counts.push_back({i, (int)count(mat[i].begin(), mat[i].end(), 1)});
    }
    // cmp: The value returned indicates whether the first argument is considered to go before the second
    sort(counts.begin(), counts.end(), [](pair<int, int>& a, pair<int, int>& b) {
       if (a.second == b.second)
      {
        return  a.first < b.first;
      }
      return  a.second < b.second;
    });
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
      ans.push_back(counts[i].first);
    }
    return ans;
  }

int main()
{
  // vector<vector<int>> a= {{21799},{64145},{88382},{60483}};
  vector<vector<int>> a= {{1,1,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,1,0,0,0},{1,1,1,1,1}};
  vector<int> ans = kWeakestRows(a , 3);
  // cout << luckyNumbers(a) << endl;
}
