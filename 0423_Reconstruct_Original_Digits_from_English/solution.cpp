/*
423. Reconstruct Original Digits from English

Level: Medium

https://leetcode.com/problems/reconstruct-original-digits-from-english
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
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
  string originalDigits(string s)
  {
    if (s.size() == 0)
      return "";
    int count[128] = {0};
    for (int i = 0; i < s.size(); i++)
      count[s[i]]++;
    int num[10];
    num[0] = count['z'];                                        //zero
    num[2] = count['w'];                                        //two
    num[4] = count['u'];                                        //four
    num[6] = count['x'];                                        //fix
    num[8] = count['g'];                                        //eight

    num[1] = count['o'] - count['z'] - count['w'] - count['u']; //one=[o]-zero-two-four
    num[3] = count['h'] - count['g'];                           //three=[h]-eight
    num[5] = count['v'] - count['s'] + count['x'];              //five=[v]-seven
    num[7] = count['s'] - count['x'];                           //seven=[s]-six
    // nine=[i]-six-eight-five
    num[9] = count['i'] - count['x'] - count['g'] - count['v'] + count['s'] - count['x'];
    string ans;
    for (int i = 0; i < 10; i++)
    {
      for (int j = num[i]; j > 0; j--)
      {
        ans += to_string(i);
      }
    }
    return ans;
  }
};