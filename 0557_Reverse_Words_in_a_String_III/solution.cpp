/*
557. Reverse Words in a String III

https://leetcode.com/problems/reverse-words-in-a-string-iii/submissions/
*/
#include <string>
using namespace std;

/*
独立反转字符串中的每个单词。
*/

class Solution {
public:
  string reverseWords(string s) {    
    int index = 0;  
    for (int i = 0; i <= s.length(); ++i) {
      if (i == s.length() || s[i] == ' ') {
        std::reverse(s.begin() + index, s.begin() + i);
        index = i + 1;
      }
    }
    return s;
  }
};
/*
  Two points
*/
class Solution {
public:
    string reverseWords(string s) {
        int start = 0, end = 0, n = s.size();
        while (start < n && end < n) {
            while (end < n && s[end] != ' ') ++end;
            for (int i = start, j = end - 1; i < j; ++i, --j) {
                swap(s[i], s[j]);
            }
            start = ++end;
        }
        return s;
    }
};