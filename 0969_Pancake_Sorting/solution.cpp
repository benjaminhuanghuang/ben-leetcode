/*
  969. Pancake Sorting

  https://leetcode.com/problems/pancake-sorting/
*/
#include <vector>
#include <queue>

using namespace std;
/*

https://zxi.mytechroad.com/blog/simulation/leetcode-969-pancake-sorting/
Solution: Simulation

Put the largest element to its position. Each element requires two flips
e.g. [3, 2, 4, 1]
largest element: 4, index: 2
flip1: [4, 2, 3, 1]
flip2: [1, 3, 2, 4]
Repeat for [1, 3, 2]…

Time complexity: O(n^2)
Space complexity: O(1)

*/
class Solution
{
public:
  vector<int> pancakeSort(vector<int> &A)
  {
    const int n = A.size();
    vector<int> ans;
    for (int i = 0; i < n - 1; ++i)
    {
      int p = max_element(begin(A), end(A) - i) - begin(A);
      ans.push_back(p + 1);
      reverse(begin(A), begin(A) + p + 1);
      ans.push_back(n - i);
      reverse(begin(A), begin(A) + n - i);
    }
    return ans;
  }
};

/*


煎饼排序。每次可以把前k个数字进行翻转，问翻转多少次之后可以达到有序状态。

就像一摞煎饼一样，每次能把铲子插入煎饼中的某个位置，然后把铲子之上的煎饼都翻转一下，问一系列位置能使结果是排序的。

把后面的数字先排好，这样再翻转前面的时候就不会影响到后面。所以，先把最大的数字放到最后，然后再把次大的位置放在倒数第二个位置……

如何把最大的数字放到最后呢？一个很简单的想法就是先把它翻转到第一个位置上去！

思路：每次找到还没排序的数字之中"最大"的数字的位置，把这个位置之前的数字翻转，这一步使得最大数字去了最前面。
第二步，再次翻转，把最大位置翻到准确的位置上去。
 */
class Solution
{
public:
  vector<int> pancakeSort(vector<int> &A)
  {
    const int n = A.size();
    vector<int> ans;
    int max = n;
    for (int i = 0; i < n - 1; ++i)
    {
       // pos is the biggest number
      int pos;
      for (pos = 0; A[pos] != max; pos++) ;  //position of the biggest number
      ans.push_back(pos + 1);
      reverse(begin(A), begin(A) + pos + 1);  // reverse [0, pos]
      ans.push_back(n - i - 1 +1);
      reverse(begin(A), begin(A) + n - i);   // reverse [0, n -i - 1]
      max--;
    }
    return ans;
  }
};
