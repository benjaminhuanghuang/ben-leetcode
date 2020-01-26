/*
914. X of a Kind in a Deck of Cards

https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/

判断一堆牌能不能分成很多组，每个组是相同的元素，并且每个组最少两张牌。
*/

#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;
/*
用map记录数列A中每个元素出现的次数，问题转化为求这些次数的公因子。如果有大于等于2的公因子，则返回true。
求公因子时采用枚举从2到最小数依次判断整除性的办法。
*/
class Solution
{
public:
  bool hasGroupsSizeX(vector<int> &deck)
  {
    unordered_map<int, int> counts;
    for (int card : deck)
      ++counts[card];

    for (int i = 2; i <= deck.size(); ++i)
    {
      if (deck.size() % i) // i 不能被deck.size()整除
        continue;
      bool ok = true;
      for (const auto &pair : counts)
        if (pair.second % i)
        {
          ok = false;
          break;
        }
      if (ok)
        return true;
    }
    return false;
  }
};
/*
https://zxi.mytechroad.com/blog/math/leetcode-914-x-of-a-kind-in-a-deck-of-cards/
Solution 2: HashTable + GCD
Time complexity: O(nlogn)
Space complexity: O(1)
*/
class Solution
{
public:
  bool hasGroupsSizeX(vector<int> &deck)
  {

    unordered_map<int, int> count; //第一个是key的类型，第二个是key对应的value的类型

    int res = 0;

    for (int i : deck)
    {
      count[i]++;
    }

    for (auto i : count)
    { //__gcd(x, y）求两个数的最大公约数， numeric 库中
      res = __gcd(i.second, res); //second是迭代器指向对应的值
    }

    return res > 1;
  }
};
