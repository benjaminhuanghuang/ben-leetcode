#include <vector>
#include <stack>

using namespace std;
class Solution
{
public:
  int subarraysDivByK(vector<int> &A, int K)
  {
    vector<int> c(K);
    c[0] = 1;
    int ans = 0;
    int sum = 0;
    for (int a : A)
    {
      sum = (sum + a % K + K) % K;
      ans += c[sum]++;
    }
    return ans;
  }
};