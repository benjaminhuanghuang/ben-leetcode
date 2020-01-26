/*
905. Sort Array By Parity

https://leetcode.com/problems/sort-array-by-parity/
*/

#include <vector>

using namespace std;


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
      vector<int> ans(A.size());
      int i =0 ;
      int j= A.size()-1;
      for(int num : A)
      {
        if(num % 2 == 0)
        {
          ans[i++] = num;
        }
        else
        {
          ans[j--] = num;
        }
      }
      return ans;
    }
};