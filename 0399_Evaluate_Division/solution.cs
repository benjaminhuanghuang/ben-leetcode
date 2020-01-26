/*
399. Evaluate Division

Equations are given in the format A / B = k, where A and B are variables represented as strings, 
and k is a real number (floating point number). Given some queries, return the answers. 
If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , 
where equations.size() == values.size(), and the values are positive. This represents the equations. 
Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
The input is always valid. You may assume that evaluating the queries will result in no division by zero and 
there is no contradiction.
*/

/*
http://bookshadow.com/weblog/2016/09/11/leetcode-evaluate-division

输入等式可以看做一个有向图

例如等式a / b = 2.0，可以转化为两条边：<a, b>，<b, a>，其长度分别为2.0，0.5

遍历equations与values，利用字典g保存有向图中各边的长度，g的keys即为顶点集

最后调用Floyd算法即可
 */
using System;
using System.Collections.Generic;

public class Solution399
{
    public double[] CalcEquation(string[,] equations, double[] values, string[,] queries)
    {
        Dictionary<string, Dictionary<string, double>> map = new Dictionary<string, Dictionary<string, double>>();
        for (int i = 0; i < equations.GetLength(0); i++)
        {
            var operand1 = equations[i, 0];
            var operand2 = equations[i, 1];
            var result = values[i];

            if (!map.ContainsKey(operand1))
                map[operand1] = new Dictionary<string, double>();
            map[operand1][operand2] = result;

            if (!map.ContainsKey(operand2))
                map[operand2] = new Dictionary<string, double>();
            map[operand2][operand1] = 1 / result;
        }

        // a/b =3, b/c=2  => a/c =6 
        foreach (string a in map.Keys)
        {
            map[a][a] = 1.0;
            foreach (string b in map.Keys)
            {
                foreach (string c in map.Keys)
                {
                    if (map.ContainsKey(b) && map[b].ContainsKey(a) &&
                        map.ContainsKey(a) && map[a].ContainsKey(c))
                    {
                        map[b][c] = map[b][a]* map[a][c];
                    }
                }
            }
        }

        List<double> res = new List<double>();
        for (int i = 0; i < queries.GetLength(0); i++)
        {
            var operand1 = queries[i, 0];
            var operand2 = queries[i, 1];
            if (map.ContainsKey(operand1) && map[operand1].ContainsKey(operand2))
            {
                res.Add(map[operand1][operand2]);
            }
            else
                res.Add(-1.0);
        }
        return res.ToArray();
    }
}

/*
 var s = new Solution399();
        var equations = new string[,]{{"a", "b"}, {"b", "c"}};
        var values = new double[]{2.0, 3.0};
        var queries = new string[,]{{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

        var res = s.CalcEquation(equations, values, queries);

 */