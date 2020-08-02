/*
535. Encode and Decode TinyURL

Level: Medium

https://leetcode.com/problems/encode-and-decode-tinyurl
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class Solution
{
public:
  // Encodes a URL to a shortened URL.
  string encode(string longUrl)
  {
    if (long_tiny.count(longUrl))
    {
      return long_tiny[longUrl];
    }
    int newId = long_tiny.size() + 1;
    string tinyUrl = intToTinyUrl(newId);
    long_tiny[longUrl] = tinyUrl;
    tiny_long[tinyUrl] = longUrl;
    return tinyUrl;
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl)
  {
    return tiny_long[shortUrl];
  }

private:
  unordered_map<string, string> long_tiny;
  unordered_map<string, string> tiny_long;
  string s{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"};

  //62 base number
  // int tinyUrlToInt(string shortUrl)
  // {
  //   int val = 0;
  //   for (int i = 0; i < shortUrl.size(); i++)
  //   {
  //     val = val * 62 + s[shortUrl[i]];
  //   }
  //   return val;
  // }

  //62 base number
  string intToTinyUrl(int val)
  {
    string s;
    while (val > 0)
    {
      int remainder = val % 62;
      val /= 62;
      s.insert(s.begin(), s[remainder]);
    }
    return s;
  }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));