/*
1079. Letter Tile Possibilities

https://leetcode.com/problems/letter-tile-possibilities/


You have a set of tiles, where each tile has one letter tiles[i] printed on it.  
Return the number of possible non-empty sequences of letters you can make.
 */

#include <string>
#include <unordered_set>

using namespace std;
/*
tiles的最大长度是7，那么理论上最多有7!种组合，这个数量非常小，可以全排列所有的的可能性然后过滤重复的数据。
 */
class Solution
{
public:
  int numTilePossibilities(string tiles)
  {
    unordered_set<string> combinations;

    search("", tiles, combinations);
    return combinations.size();
  }

  void search(string curr, string remaining, unordered_set<string> &combinations)
  {
    for (int i = 0; i < remaining.length(); i++)
    {
      string next = curr + remaining[i];
      if (combinations.find(next) == combinations.end())
      {
        combinations.insert(next);
      }

      string cpy = "" + remaining;
      cpy.erase(cpy.begin() + i);

      search(next, cpy, combinations);
    }
  };
};