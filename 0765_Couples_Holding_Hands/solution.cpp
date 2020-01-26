/*
765. Couples Holding Hands

https://leetcode.com/problems/couples-holding-hands/
*/

#include <string>
#include <climits>
#include <vector>
#include <unordered_map>

using namespace std;

/*
https://mli9502.github.io/2018/10/24/leetcode-765-Couples-Holding-Hands/
*/
class Solution
{
public:
  int minSwapsCouples(vector<int> &row)
  {
    unordered_map<int, int> hm;
    for (int i = 0; i < row.size(); i++)
    {
      // Assign group label to couples.
      // 0 1: 0
      // 2 3: 2
      // 4 5: 4
      // ...
      hm[row[i]] = row[i] & (~0x1);
    }

    // For each pair, if they are in two groups, we union the two groups together.
    // Every time we do a union, we have one less connected components.
    // The maximum number of connected components we can have is the number of couples, which is row.size() / 2.
    int maxNumOfConnectedComps = row.size() / 2;
    int initConnectedComps = maxNumOfConnectedComps;
    for (int i = 0; i < row.size(); i += 2)
    {
      int g1 = uf_find(hm, row[i]);
      int g2 = uf_find(hm, row[i + 1]);
      if (g1 != g2)
      {
        uf_union(hm, g1, g2);
        initConnectedComps--;
      }
    }
    // Now, initConnectedComps represents the number of connected components we have.
    // # of swaps needed = max # of connected components - # of connected components we have.
    // This is because in a given connected component, for each swap, we can at most generate one additional connected component.
    // So, # of swaps needed + # of connected components we currently have = max # of connected components.
    return maxNumOfConnectedComps - initConnectedComps;
  }
  void uf_union(unordered_map<int, int> &hm, int g1, int g2)
  {
    hm[g2] = g1;
  }
  int uf_find(unordered_map<int, int> &hm, int val)
  {
    if (hm[val] == val)
    {
      return val;
    }
    else
    {
      return uf_find(hm, hm[val]);
    }
  }
};

/*
https://blog.csdn.net/magicbean2/article/details/79628194


采用贪心的思路：为了便于快速查找某个id的人所处的位置，我们定义一个哈希表，表示从某人的id到其在row中的位置。
然后就开始扫描row中的偶数位。根据在该偶数位上的人的id，可以推出其另一半所处的位置。如果他的另一半不在他接下来的位置，
那么我们就交换下一位置和它的另一半的位置（并且记得更新哈希表）。这样最后返回总共的交换次数即可。
*/
class Solution2{
public:
    int minSwapsCouples(vector<int>& row) {
        unordered_map<int, int> hash;   // map from person id to position
        for (int i = 0; i < row.size(); ++i) {
            hash[row[i]] = i;
        }
        int ret = 0;
        for (int i = 0; i < row.size(); i += 2) {
            int p1 = row[i];
            int p2 = p1 % 2 == 0 ? p1 + 1 : p1 - 1; // its couple's id
            if (row[i + 1] != p2) {
                int p2_pos = hash[p2];
                hash[row[i + 1]] = p2_pos;
                hash[p2] = i + 1;
                swap(row[i + 1], row[p2_pos]);
                ++ret;
            }
        }
        return ret;
    }
};