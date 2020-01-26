/*
1013. Partition Array Into Three Parts With Equal Sum

https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/
*/
#include <vector>
#include <numeric>

using namespace std;

/*
1、检查总数是否能被3整除;
2、循环遍历数组A，计算和的一部分;如果找到平均值，则将该部分重置为0，并增加计数器;
3、到最后，如果平均可以看到至少3次，返回true;否则返回假。
注意:如果在数组结束前找到2次平均值(sum / 3)，那么剩下的部分也等于平均值。因此，计数器达到3后无需继续。
*/
class Solution
{
public:
  bool canThreePartsEqualSum(vector<int> &A)
  {
    int sum = accumulate(A.begin(), A.end(), 0);
    if (sum % 3 != 0)
    {
      return false;
    }
    int partSum = 0, count = 0;

    for (int a : A)
    {
      partSum += a;
      if (partSum != sum / 3)
      {
        continue;
      } // not the average: sum / 3
      if (++count == 3)
      {
        return true;
      }         // find an average, increase the counter.
      partSum = 0; // reset part.
    }
    return false;
  }
};