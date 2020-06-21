/*
168. Excel Sheet Column Title

Level: Easy

https://leetcode.com/problems/excel-sheet-column-title
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
  /*
    对于小于26的数字, 只需要对26取余，然后减去1，加上字符A即可，
    对于26来说，如果还是这么做的话就会出现问题，因为对26取余是0，减去1后成为-1，加上字符A后，并不等于字符Z。
    所以对于能被26整除的数我们得分开处理:
    能整除26的，直接在结果res上加上字符Z，然后n自减去26；
    不能的话，就按照一般的处理，n要减去这个余数。之后n要自除以26，继续计算下去

    合并if和else，写的更简洁一些。
    用一个小trick，比如对于26来说，我们先让n自减1，变成25，然后再对26取余，得到25，此时再加上字符A，就可以得到字符Z了。
    这对其他的不能整除26的数也是成立的，
    https://www.cnblogs.com/grandyang/p/4227618.html
  */
  string convertToTitle_v1(int n)
  {
    string res = "";
    while (n)
    {
      if (n % 26 == 0)
      {
        res += 'Z';
        n -= 26;
      }
      else
      {
        res += n % 26 - 1 + 'A';
        n -= n % 26;
      }
      n /= 26;
    }
    reverse(res.begin(), res.end());
    return res;
  }
  string convertToTitle(int n)
  {
    string title;
    while (n > 0)
    {
      n--;
      title += (n % 26) + 'A';

      n /= 26;
    }
    return string(title.rbegin(), title.rend());
  }
};