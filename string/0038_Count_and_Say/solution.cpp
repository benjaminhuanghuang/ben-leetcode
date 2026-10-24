/*
38. Count and Say
https://leetcode.com/problems/count-and-say/
*/

#include <string>

using namespace std;

class Solution {
public:
  string countAndSay(int n) {
    string ans = "1";
    for (int i = 1; i < n; ++i)
      ans = say(ans);
    return ans;
  }

private:
  /*
   say num 1 , 11, 21
   Using tow pointer to count the same digit in the num
  */
  string say(const string& num){
    string ans;
    int start = 0, len = num.length();
    for (int end = 1; end <= len; ++end)
      if (end == len || num[start] != num[end]) {
        int count = end - start;
        ans += '0' + count;   // convert count from int to char   ans += 'count'num[start]
        ans += num[start];
        start = end;
      }
    return ans;
  }
};