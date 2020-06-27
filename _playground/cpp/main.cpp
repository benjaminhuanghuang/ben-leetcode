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
char findDigit(vector<int> &A, int limit)
  {
    char digit = '-';
    for (int i = A.size() - 1; i >= 0; i--)
    {
      if (A[i] <= limit && A[i] >= 0)
      {
        digit = A[i] + '0';
        A[i] = -1;
        break;
      }
    }
    return digit;
  }

  string largestTimeFromDigits(vector<int> &A)
  {
    sort(A.begin(), A.end());

    string time{"00:00"};

    //
    time[0] = findDigit(A, 2);
    //
    int limit = time[0] == '2' ? 3 : 9;
    time[1] = findDigit(A, limit);
    //
    time[3] = findDigit(A, 5);
    //
    time[4] = findDigit(A, 9);

    if (time.find('-') != string::npos)
      return "";
    return time;
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
  vector<int> input = {2,0,6,6};
  auto ans = largestTimeFromDigits(input);
  cout << ans << endl;
}
