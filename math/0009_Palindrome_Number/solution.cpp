/*
9. Palindrome Number

https://leetcode.com/problems/palindrome-number/
*/
#include <string>
using namespace std;

class Solution
{
public:
  bool isPalindrome(int x)
  {
    string s = to_string(x);
    return s == string(rbegin(s), rend(s));
  }
};

/*
	https://www.programcreek.com/2013/02/leetcode-palindrome-number-java/
 	Better
 */
class Solution
{
public:
  bool isPalindrome(int x)
  {
    if (x < 0)
			return false;
 
		// initialize how many zeros
		int div = 1;
		while (x / div >= 10) {
			div *= 10;
		}
 
		while (x != 0) {
			int left = x / div;
			int right = x % 10;
 
			if (left != right)
				return false;
 
			x = (x % div) / 10;  // remove left: x % div , remove right: (x % div) / 10
			div /= 100;   // two digits were removed
		}
		return true;
  }
};