/*
796. Rotate String

Level: Easy

https://leetcode.com/problems/rotate-string
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
  "abcdeabcde"
  "abced"

*/

class Solution
{
public:
  bool rotateString(string A, string B)
  {
    if (A.size() != B.size())
      return false;
    if (A == B)
      return true;
    // find() return biggest unsign int 18446744073709551615
    return (int)((A + A).find(B)) > 0;
  }

  bool rotateString(string A, string B)
  {
    if (A.size() != B.size())
      return false;
    if (A.empty() && B.empty())
      return true;

    for (int i = 0; i < A.size(); i++)
    {
      if (A == B)
        return true;
      char temp = A[0];
      A.erase(0, 1);
      A += temp;
    }
    return false;
  }
};