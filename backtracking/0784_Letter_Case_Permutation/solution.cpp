/*
784. Letter Case Permutation

*/
#include <vector>
#include <string>

using namespace std;

/*
  Too slow
*/
class Solution
{
public:
  vector<string> letterCasePermutation(string S)
  {
    vector<string> ans;
    dfs(S, 0, "", ans);
    return ans;
  }


  void dfs(string &S, int start, string curr, vector<string> &ans)
  {
      if(curr.length() == S.length())
      {
        ans.push_back(curr);
        return;
      }

      for(int i = start; i< S.length(); i++)
      {
        if (!isalpha(S[i]))
        {
          dfs(S, i + 1, curr+ S[i], ans);
        }  
        else
        {
          char c = S[i];
          dfs(S, i + 1, curr+ c, ans);
          c ^= (1 << 5);
          dfs(S, i + 1, curr+ c, ans);
        }
      }
  }
};

/*
  http://zxi.mytechroad.com/blog/searching/leetcode-784-letter-case-permutation/
*/
class Solution {
public:
  vector<string> letterCasePermutation(string S) {
    vector<string> ans;
    dfs(S, 0, ans);
    return ans;
  }
private:
  void dfs(string& S, int s, vector<string>& ans) {
    if (s == S.length()) {
      ans.push_back(S);
      return;      
    }
    dfs(S, s + 1, ans);    
    if (!isalpha(S[s])) return;          
    S[s] ^= (1 << 5);
    dfs(S, s + 1, ans);
    S[s] ^= (1 << 5);
  }
};