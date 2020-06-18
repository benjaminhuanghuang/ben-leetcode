#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_set>

using namespace std;

vector<int> luckyNumbers(vector<vector<int>> &matrix)
{
  int rows = matrix.size();
  int cols = matrix[0].size();
  int minRow[rows];
  int maxCol[cols];
  std::fill(maxCol, maxCol + cols, INT_MIN);
  std::fill(minRow, minRow + rows, INT_MAX);

  for (int row = 0; row < rows; ++row)
  {
    for (int col = 0; col < cols; ++col)
    {
      minRow[row] = min(matrix[row][col], minRow[row]);
      maxCol[col] = max(matrix[row][col], maxCol[col]);
    }
  }
  vector<int> lockyNums;
  for (int row = 0; row < rows; ++row)
  {
    for (int col = 0; col < cols; ++col)
    {
      if (minRow[row] == maxCol[col])
        lockyNums.push_back(minRow[row]);
    }
  }
  return lockyNums;
}

string reformat(string s)
{
  string letters;
  string digits;

  for (char c : s)
  {
    if (isdigit(c))
    {
      digits += c;
    }
    else
    {
      letters += c;
    }
  }
  if (abs((int)letters.length() - (int)digits.length()) > 1)
  {
    return "";
  }
  string formatted;
  auto letterIt = letters.begin();
  auto digitIt = digits.begin();

  if (letters.size() > digits.size())
  {
    for (int i = 0; i < digits.size(); i++)
    {
      formatted += *(letterIt++);
      formatted += *(digitIt++);
    }
    formatted += *(letterIt++);
  }
  else
  {
    for (int i = 0; i < letters.size(); i++)
    {
      formatted += *(digitIt++);
      formatted += *(letterIt++);
    }
    if (digits.size() > letters.size())
      formatted += *(digitIt++);
  }

  return formatted;
}
int main()
{
  // vector<vector<int>> a= {{21799},{64145},{88382},{60483}};
  vector<vector<int>> a= {{78006,52517,25163},{45858,23927,10453}};
  vector<int> ans = luckyNumbers(a);
  // cout << luckyNumbers(a) << endl;
}
