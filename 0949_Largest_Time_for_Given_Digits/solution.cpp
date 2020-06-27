/*
949. Largest Time for Given Digits

Level: Easy

https://leetcode.com/problems/largest-time-for-given-digits
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
private:
  char findDigit(vector<int> &A, int limit)
  {
    char digit = '-';
    for (int i = A.size() - 1; i >= 0; i--)
    {
      if (A[i] <= limit && A[i] >= 0)
      {
        digit = A[i] + '0';
        A[i] = -1;
        break;
      }
    }
    return digit;
  }

public:
  /*
    Failed [0,6,2,6]
  */
  string largestTimeFromDigits_wrong(vector<int> &A)
  {
    sort(A.begin(), A.end());

    string time{"00:00"};

    //
    time[0] = findDigit(A, 2);
    //
    int limit = time[0] == '2' ? 3 : 9;
    time[1] = findDigit(A, limit);
    //
    time[3] = findDigit(A, 5);
    //
    time[4] = findDigit(A, 9);

    if (time.find('-') != string::npos)
      return "";
    return time;
  }
 string largestTimeFromDigits(vector<int>& A) 
    {
        sort(A.begin(), A.end(), greater<int>());
        do 
        {
            if (A[0] * 10 + A[1] < 24 && A[2] * 10 + A[3] < 60) return to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]);
        } while (next_permutation(A.begin(), A.end(), greater<int>()));
        return "";
    }
  /*
    dfs http://www.noteanddata.com/leetcode-949-Largest-Time-for-Given-Digits-java-solution-note.html
  */
};