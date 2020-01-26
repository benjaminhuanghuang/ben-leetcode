/*
839. Similar String Groups [Hard]

https://leetcode.com/problems/similar-string-groups/
*/
#include <string>
#include <climits>
#include <vector>
#include <unordered_set>

#include "common/DSU.h"

using namespace std;

/*

*/
class Solution {
public:
  int numSimilarGroups(vector<string>& A) {
    DSU dsu(A.size());
    for (int i = 0; i < A.size(); ++i)
      for (int j = i + 1; j < A.size(); ++j)
        if (similar(A[i], A[j]))
          dsu.Union(i, j);
    return dsu.Size();
  }
private:
  bool similar(const string& a, const string& b) {
    int diff = 0;
    for (int i = 0; i < a.length(); ++i)
      if (a[i] != b[i] && ++diff > 2) return false;    
    return true;
  }
};