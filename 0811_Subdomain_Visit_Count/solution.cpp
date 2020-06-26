/*
811. Subdomain Visit Count

Level: Easy

https://leetcode.com/problems/subdomain-visit-count
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
  vector<string> subdomainVisits(vector<string> &cpdomains)
  {
    unordered_map<string, int> counts;

    for (const string &cpdomain : cpdomains)
    {
      size_t index = cpdomain.find(' ');
      int count = std::stoi(cpdomain.substr(0, index));
      string domain = cpdomain.substr(index + 1);
      while (true)
      {
        // split the domain by ''.
        counts[domain] += count;
        size_t i = domain.find('.');
        if (i == string::npos)
          break;
        domain = domain.substr(i + 1);
      }
    }
    vector<string> ans;
    for (const auto &kv : counts)
      ans.push_back(std::to_string(kv.second) + " " + kv.first);
    return ans;
  }
};