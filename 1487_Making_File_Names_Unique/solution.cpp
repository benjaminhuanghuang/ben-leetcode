/*
1487. Making File Names Unique

Level: Medium

https://leetcode.com/problems/making-file-names-unique
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class Solution
{
public:
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
};