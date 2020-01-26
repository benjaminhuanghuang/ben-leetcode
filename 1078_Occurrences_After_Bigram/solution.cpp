/*
1078. Occurrences After Bigram

Given words first and second, consider occurrences in some text of the form "first second third", where second comes immediately after first, and third comes immediately after second.

For each such occurrence, add "third" to the answer, and return the answer.

 

Example 1:

Input: text = "alice is a good girl she is a good student", first = "a", second = "good"
Output: ["girl","student"]

Example 2:

Input: text = "we will we will rock you", first = "we", second = "will"
Output: ["we","rock"]


 */
#include <vector>
#include <sstream>
#include <string>

using namespace std;
/*
C++没有split()函数，一个可以替换的方案是使用stringstream类，该类会模拟字符串读入操作，即实现字符串按空格分割。
初始化三个字符串，分别是f,s,t，读入到第三个里，前两个保留的是前两次读入的结果。这样进行判断是比较优雅的操作。
 */
class Solution
{
public:
  vector<string> findOcurrences(string text, string first, string second)
  {
    vector<string> ans;
    stringstream ss(text);
    string w1, w2, w3;
    while (ss >> w3)
    {
      if (w1 == first && w2 == second)
        ans.push_back(w3);
      w1 = w2;
      w2 = w3;
    }
    return ans;
  }
};