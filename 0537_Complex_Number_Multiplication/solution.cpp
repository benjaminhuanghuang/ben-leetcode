/*
537. Complex Number Multiplication

https://leetcode.com/problems/complex-number-multiplication/
*/
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

/*
利用好定义i2=-1就可以解题，
另一个考察点其实是对字符的处理，需要把字符串中的实部和虚部分离开并进行运算，可以用STL的find_last_of函数来找到加号的位置，
然后分别拆出实部虚部，进行运算后再变回字符串，
*/
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int n1 = a.size(), n2 = b.size();
        auto p1 = a.find_last_of("+"), p2 = b.find_last_of("+");

        int a1 = stoi(a.substr(0, p1));
        int b1 = stoi(b.substr(0, p2));
        int a2 = stoi(a.substr(p1 + 1, n1 - p1 - 2));
        int b2 = stoi(b.substr(p2 + 1, n2 - p2 - 2));
        
        int r1 = a1 * b1 - a2 * b2, r2 = a1 * b2 + a2 * b1;
        return to_string(r1) + "+" + to_string(r2) + "i";
    }
};

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        istringstream is1(a), is2(b);
        int a1, a2, b1, b2, r1, r2;
        char plus;
        is1 >> a1 >> plus >> a2;
        is2 >> b1 >> plus >> b2;
        r1 = a1 * b1 - a2 * b2, r2 = a1 * b2 + a2 * b1;
        return to_string(r1) + "+" + to_string(r2) + "i";
    }
};