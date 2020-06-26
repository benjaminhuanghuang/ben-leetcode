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
bool rotateString(string A, string B)
{
  if (A.size() != B.size())
    return false;
  int a = (A + A).find(B);
  bool c = a > 0;

  cout << string("a").find("b") << endl;
  cout << (int)(string("a").find("b")) << endl;
  bool d = string("a").find("b") > 0;
  return a > 0;
}

int main()
{
  // vector<vector<int>> a= {{21799},{64145},{88382},{60483}};
  // vector<string> input = {"gta", "gta(1)", "gta", "avalon"};
  // vector<int> input{1,2,0,0,2,1};//{10,20,20};//{69, 0, 0, 0, 69};

  // auto ans = avoidFlood(input);
  // for (auto i : ans)
  // {
  //   cout << i << endl;
  // }
  // int ans = arrangeCoins(5);
  auto ans = rotateString("abcde", "abced");
  cout << ans << endl;
}
