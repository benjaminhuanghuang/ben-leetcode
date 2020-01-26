package cn.huang.leetcode;
/*
800. Similar RGB Color

In the following, every capital letter represents some hexadecimal digit from 0 to f.

The red-green-blue color "#AABBCC" can be written as "#ABC" in shorthand.  For example, "#15c" is shorthand for the color "#1155cc".

Now, say the similarity between two colors "#ABCDEF" and "#UVWXYZ" is -(AB - UV)^2 - (CD - WX)^2 - (EF - YZ)^2.

Given the color "#ABCDEF", return a 7 character color that is most similar to #ABCDEF, and has a shorthand (that is, it can be represented as some "#XYZ"

Example 1:
Input: color = "#09f166"
Output: "#11ee66"
Explanation:
The similarity is -(0x09 - 0x11)^2 -(0xf1 - 0xee)^2 - (0x66 - 0x66)^2 = -64 -9 -0 = -73.
This is the highest among any shorthand color.

Note:

    color is a string of length 7.
    color is a valid RGB color: for i > 0, color[i] is a hexadecimal digit from 0 to f
    Any answer which has the same (highest) similarity as the best answer will be accepted.
    All inputs and outputs should use lowercase letters, and the output is 7 characters.

 */


/*
我们发现R,G,B三个分量之间是相互独立的，所以可以各个单独进行计算。对于每个分量，假如对应的输入为s，那么最多有三个候选的最近颜色：string(2, s[0] - 1), string(2, s[0])以及string(2, s[0] + 1)。所以我们分别进行比较，选出距离最小的即可。

值得注意的是，当s[0] == '9'或者s[0] == 'a'的时候，我们需要进行特殊处理，否则在16进制转换的时候会出错。

*/

import java.util.Arrays;

public class LC_0800_SimilarRGBColor {
    /*
    https://zxi.mytechroad.com/blog/string/leetcode-simple-rgb-color/
    R, G, B are independent, find the closest color for each channel separately.
     */
    String similarRGB(String color) {
        String hex = "0123456789abcdef";

        int[] rgb = new int[3];
        for (int i = 0; i < 3; ++i)
            rgb[i] = hex.indexOf(color.charAt(2 * i + 1) * 16 + hex.indexOf(color.charAt(2 * i + 2)));

        char[] ans = new char[7];
        Arrays.fill(ans, '#');

        for (int i = 0; i < 3; ++i) {
            int best = Integer.MAX_VALUE;
            for (int j = 0; j < 16; ++j) {
                int diff = Math.abs(j * 16 + j - rgb[i]);
                if (diff >= best)
                    continue;
                best = diff;
                ans[2 * i + 1] = ans[2 * i + 2] = hex.charAt(j);
            }
        }
        return String.valueOf(ans);
    }
}
