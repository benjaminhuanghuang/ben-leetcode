package cn.huang.leetcode;

/*
777. Swap Adjacent in LR String

In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one
occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR". Given the starting string start and
the ending string end, return True if and only if there exists a sequence of moves to transform one string to the other.

Example:

Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
Output: True
Explanation:
We can transform start to end following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX

Note:

    1 <= len(start) = len(end) <= 10000.
    Both start and end will only consist of characters in {'L', 'R', 'X'}.


 */
/*
一个只含有L，R，X三个字符的字符串，然后说有两种操作，一种是把 "XL" 变成 "LX"，另一种是把 "RX" 变成 "XR"。

一个不变量是，字符串中的“L”和“R”字符永远不能穿过对方 -> 在线上行走的人不能相互穿过。这意味着，当忽视"X“，只读“L”和“R”时，起始字符串和目标字符串必须相同。这是条件1。
此外，“L”只会往左前进，同样，“R”只会往右前进。这是条件2。那么对于相同的”L“，如果在end字符串的位置比start中右移了，那么就违反了条件2。
有了这些想法，我们将分别查看这两个条件。如果他们都是真的，那么答案是true，否则就是false。
 */
public class LC_0777_SwapAdjacentinLRString {
    public boolean canTransform(String start, String end) {
        if (!start.replace("X", "").equals(end.replace("X", "")))
            return false;

        int t = 0;
        for (int i = 0; i < start.length(); ++i)
            if (start.charAt(i) == 'L') {
                while (end.charAt(t) != 'L') t++;
                if (i < t) return false; //发现end中L往右移动了
                t++;
            }

        t = 0;
        for (int i = 0; i < start.length(); ++i)
            if (start.charAt(i) == 'R') {
                while (end.charAt(t) != 'R') t++;
                if (i > t) return false; //发现end中R往左移动了
                t++;
            }

        return true;
    }
}
