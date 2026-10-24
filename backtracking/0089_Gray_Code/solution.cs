/*
89. Gray Code

The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. 
A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/

using System.Collections.Generic;

public class Solution089 {
    // start with 0, use an array to store all visited number. 
    // change the first bit of the number, if it has not visited, add to visited array and continue with this new number.  
    // If it has visited, just return and try changing the second bit of the number.
    // 00 to visited array
    // 00 try change first bit -> 01    add 01 to visited array
    // 01 try change first bit -> 00   already visited
    // 01 try change second bit -> 11    add 11 to visited
    // 11 try change first bit -> 10 add 10 to visited
    public IList<int> GrayCode(int n) {
        var res = new List<int>();
        var count = 1 << n;
        var visited = new bool[count];

        var start = 0;

        while (count-- > 0)
        {
            res.Add(start);
            visited[start] = true;
            for (int i = 0; i < n; i++)
            {
                var next = start ^ (1 << i);  //only one bit is different
                if (visited[next]) 
                    continue;
                start = next;
                break;
            }
        }
        return res;
    }

    // https://dyang2016.wordpress.com/2016/10/10/89-gray-code/
    public IList<int> GrayCode2(int n)
    {
        var res = new List<int>();
        var count = 1 << n;
        for (int i = 0; i < count; i++)             
        {                 
            res.Add(i ^ (i>>1));
        }
        return res;
    }
}




