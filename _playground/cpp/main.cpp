#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int maxNumberOfBalloons(string text)
  {
    unordered_map<char, int> counter;

    for (char c : text)
    {
      counter[c]++;
    }

    int count = 0;
    while (counter['b'] > 0)
    {
      for (char c : "balloon")
      {
        if (counter[c] <=0)
        {
          return count;
        }
        counter[c]--;
      }
      count++;
    }
    return count;
  }

int main()
{
  // vector<vector<int>> a= {{21799},{64145},{88382},{60483}};
  string input = "nlaebolko";
  auto ans = maxNumberOfBalloons(input);
  cout << ans << endl;
}
