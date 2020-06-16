#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> buildArray(vector<int> &target, int n)
{
  vector<string> arr;
  int i = 0;
  int num = 1;
  while (num <= n && i < target.size())
  {
    while (num < target[i] )
    {
      arr.push_back("Push");
      arr.push_back("Pop");
      num++;
    }
    //
    arr.push_back("Push");
    i++;
    num++;
  }
  return arr;
}


int main()
{
  vector<int> target = {1, 2};
  vector<string> arr = buildArray(target, 4);

  for (auto s : arr)
  {
    cout << s << ",";
  }

  cout << endl;
  return 0;
}

