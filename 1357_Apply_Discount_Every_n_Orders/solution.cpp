/*
1357. Apply Discount Every n Orders [Facebook]

Level: Medium

https://leetcode.com/problems/apply-discount-every-n-orders
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

class Cashier
{
public:
  Cashier(int n, int discount, vector<int> &products, vector<int> &prices)
  {
    l = n;
    disc = discount;
    int z = products.size();
    for (int i = 0; i < z; i++)
      mp[products[i]] = prices[i];
  }

  double getBill(vector<int> product, vector<int> amount)
  {
    k++;
    double sum = 0;
    int m = product.size();
    for (int i = 0; i < m; i++)
    {
      sum += (amount[i] * mp[product[i]]);
    }
    if (k % l == 0)
    {
      sum = sum - ((disc * sum)) / 100.0;
    }
    return sum;
  }

private:
  int k = 0, l, disc;
  unordered_map<int, int> mp;
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */