/*
1170. Compare Strings by Frequency of the Smallest Character

Level: Easy

https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character
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
  vector<int> numSmallerByFrequency_slow(vector<string> &queries, vector<string> &words)
  {
    vector<int> qs, ws;
    for (string &q : queries)
    {
      qs.push_back(getFrequency(q));
    }
    for (string &w : words)
    {
      ws.push_back(getFrequency(w));
    }
    vector<int> res;
    for (int q : qs)
    {
      int count = 0;
      for (int w : ws)
      {
        if (w > q)
          count++;
      }
      res.push_back(count);
    }
    return res;
  }
  vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> wordVals;
        for(auto w: words) wordVals.push_back(getFrequency(w));

        sort(wordVals.begin(), wordVals.end());   // Key point
        vector<int> op(queries.size(), 0);
        int k=0;
        for(auto q: queries) {
            int fV = getFrequency(q);
            auto it = upper_bound(wordVals.begin(), wordVals.end(), fV);
            if(it!= wordVals.end()) 
                op[k] = wordVals.end()-it;
            else
                op[k] = 0;
            k++;
        }
        return op;
    }
private:
  int getFrequency(string &word)
  {
    vector<int> counts(26, 0);
    for (char w : word)
    {
      counts[w - 'a']++;
    }
    for (int i = 0; i < 26; ++i)
    {
      if (counts[i] != 0)
        return counts[i];
    }
    return 0;
  }
};