/*
609. Find Duplicate File in System

https://leetcode.com/problems/find-duplicate-file-in-system/
*/
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/*
  https://zxi.mytechroad.com/blog/string/leetcode-609-find-duplicate-file-in-system/
*/
class Solution
{
public:
  vector<vector<string>> findDuplicate(vector<string> &paths)
  {
    unordered_map<string, vector<string>> files; // content -> filenames
    for (const string &path : paths)
    {
      string folder;
      int i = 0;
      while (path[i] != ' ')
        folder += path[i++];
      while (i < path.length())
      {
        string filename;
        string content;
        ++i; // ' '
        while (path[i] != '(')
          filename += path[i++];
        ++i; // '('
        while (path[i] != ')')
          content += path[i++];
        ++i; // ')'
        files[content].push_back(folder + "/" + filename);
      }
    }
    vector<vector<string>> ans;
    for (auto &kv : files)
      if (kv.second.size() > 1)
        ans.push_back(std::move(kv.second));
    return ans;
  }
};