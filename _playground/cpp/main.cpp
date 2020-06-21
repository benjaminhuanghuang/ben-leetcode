#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <utility>

using namespace std;
int bitwiseComplement(int N)
  {
    if (N == 0)
      return 1;

    int ans = 0;
    bool find1 = false;
    for (int i = 31; i >= 0; i--)
    {
      int mask = 1 << i;
      if ((N & mask) && !find1)
      {
        find1 =  N & mask;
      }
      if ((N & mask) == 0 && find1)
      {
        ans += 1 << i;
      }
    }
    return ans;
  }

int main()
{
  // vector<vector<int>> a= {{21799},{64145},{88382},{60483}};
  auto input = 5;
  auto ans = bitwiseComplement(input);
  cout << ans << endl;
}
