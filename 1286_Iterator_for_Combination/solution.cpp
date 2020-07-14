/*
1286. Iterator for Combination

Level: Medium

https://leetcode.com/problems/iterator-for-combination
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
  characters 可以不连续
*/

class CombinationIterator
{
private:
  string cur;
  string end;
  bool flag;
  string characters;
  int combinationLength;

public:
  CombinationIterator(string characters, int combinationLength)
  {
    cur = characters.substr(0, combinationLength);
    end = characters.substr(characters.size() - combinationLength);
    flag = 1;
    this->characters = characters;
    this->combinationLength = combinationLength;
  }

  string next()
  {
    if (flag)
    {
      flag = 0;
      return cur;
    }

    int i = cur.size() - 1;
    while (i >= 0 && cur[i] == characters[i + characters.size() - combinationLength])
      i--;
    int j = 0;
    while (cur[i] != characters[j])
      j++;
    for (int k = i; k < cur.size(); k++)
      cur[k] = characters[j + 1 + k - i]; // cur[i] = characters[j+1]

    return cur;
  }

  bool hasNext()
  {
    return cur != end;
  }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */