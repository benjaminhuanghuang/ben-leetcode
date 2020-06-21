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
int numEquivDominoPairs(vector<vector<int>> &dominoes)
  {
    set<pair<int, int>> dimensions;

    for (auto d : dominoes)
    {
      dimensions.insert({max(d[1], d[0]), min(d[1], d[0])});
    }

    return dimensions.size();
  }
int dayOfYear(string date)
{
  int year = stoi(date.substr(0, 4));
  int month = stoi(date.substr(5, 2));
  int day = stoi(date.substr(8, 2));

  int const days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (month > 1)
  {
    for (int i = 1; i < month; i++)
    {
      day += days[i - 1];
      if (i == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
      {
        day++;
      }
    }
  }
  return day;
}

int main()
{
  // vector<vector<int>> a= {{21799},{64145},{88382},{60483}};
  string input = "2019-01-09";
  auto ans = dayOfYear(input);
  cout << ans << endl;
}
