/*
299. Bulls and Cows

Level: Easy

https://leetcode.com/problems/bulls-and-cows
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
  string getHint(string secret, string guess)
  {
    int bulls = 0;
    int cows = 0;

    unordered_map<char, int> counter;

    //check bull
    for (int i = 0; i < secret.length(); i++)
    {
      char s = secret[i];
      char g = guess[i];

      if (s == g)
      {
        //  guess match secret number exactly in both digit and position (called "bulls")
        bulls++;
      }
      else
      {
        // digits match the secret number but locate in the wrong position (called "cows").
        counter[s]++;
        if (counter[s] <= 0)
        {
          cows++;
        }
        counter[g]--;
        if (counter[g] >= 0)
        {
          cows++;
        }
      }
    }

    return to_string(bulls) + 'A' + to_string(cows) + 'B';
  }

  string getHint_v2(string secret, string guess)
  {
    //maintain a count of each digit seen so far in an array.
    vector<int> count(10, 0);
    int bulls = 0, cows = 0;
    for (int i = 0; i < secret.size(); ++i)
    {
      if (secret[i] == guess[i])
        ++bulls;
      else
      {
        if (count[secret[i] - '0']++ < 0)
          ++cows;
        if (count[guess[i] - '0']-- > 0)
          ++cows;
      }
    }
    return to_string(bulls) + 'A' + to_string(cows) + 'B';
  }
};