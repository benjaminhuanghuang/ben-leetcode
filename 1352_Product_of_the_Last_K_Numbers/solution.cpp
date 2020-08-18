/*
1352. Product of the Last K Numbers

Level: Medium

https://leetcode.com/problems/product-of-the-last-k-numbers
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
*/

class ProductOfNumbers
{
public:
  ProductOfNumbers()
  {
    props.push_back(1);
  }

  void add(int num)
  {
    if (num == 0)
    {
      props.clear();
      props.push_back(1);
    }
    else
    {
      props.push_back(num * props.back());
    }
  }

  int getProduct(int k)
  {
    if (props.size() > k)
      return props.back() / props[props.size() - k - 1];

    return 0;
  }

private:
  vector<int> props;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */