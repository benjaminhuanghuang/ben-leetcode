#include <vector>
#include <string>
#include <unordered_set>

using namespace std;
/*
https://zxi.mytechroad.com/blog/string/leetcode-937-reorder-log-files/
*/
class Solution
{
public:
  vector<string> reorderLogFiles(vector<string> &logs)
  {
    auto alpha_end = std::stable_partition(begin(logs), end(logs),
                                           [](const string &log) { return isalpha(log.back()); });
    std::sort(begin(logs), alpha_end, [](const string &a, const string &b) {
      return a.substr(a.find(' ')) < b.substr(b.find(' '));
    });
    return logs;
  }
};

/*

*/
class Solution
{
public:
  static bool cmp(string A, string B)
  {
    // substring from pos to end
    string subA = A.substr(A.find(' ') + 1);
    string subB = B.substr(B.find(' ') + 1);
    if (isdigit(subA[0]))
      return false;
    else if (isdigit(subB[0]))
      return true;
    if (subA.compare(subB) == 0)
    {
      return A.compare(B);
    }
    return subA.compare(subB) < 0;
  }
  vector<string> reorderLogFiles(vector<string> &logs)
  {
    stable_sort(logs.begin(), logs.end(), cmp);
    return logs;
  }
};
