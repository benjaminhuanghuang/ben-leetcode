package cn.huang.leetcode;
/*
 399. Evaluate Division
Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real
number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0.
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries ,
where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].
The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is
no contradiction.
 */



/*
    1) 已知: a / b = 2, b / c = 3， 求 a / c
    2) 已知: a / c = 2, b / c = 3， 求 a / b
    3) 已知: a / b = 2, a / c = 3， 求 b / c
*/

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

public class LC_0399_EvaluateDivision {
    /*
        建立一个graph， graph的边是两个数运算的结果

     */
    Map<String, HashMap<String, Double>> g = new HashMap<>();

    public double[] calcEquation_DFS(String[][] equations, double[] values, String[][] queries) {
        for (int i = 0; i < equations.length; ++i) {
            String x = equations[i][0];
            String y = equations[i][1];
            double value = values[i];
            // g[x][y] = value
            g.computeIfAbsent(x, l -> new HashMap<String, Double>()).put(y, value);
            // g[y][x] = 1/ value
            g.computeIfAbsent(y, l -> new HashMap<String, Double>()).put(x, 1.0 / value);
        }

        double[] ans = new double[queries.length];

        for (int i = 0; i < queries.length; ++i) {
            String x = queries[i][0];
            String y = queries[i][1];
            if (!g.containsKey(x) || !g.containsKey(y)) {
                ans[i] = -1.0;
            } else {
                ans[i] = divide(x, y, new HashSet<String>());
            }
        }

        return ans;
    }

    private double divide(String x, String y, Set<String> visited) {
        if (x.equals(y)) return 1.0;
        visited.add(x);
        if (!g.containsKey(x)) return -1.0;
        for (String neighbor : g.get(x).keySet()) {
            if (visited.contains(neighbor))
                continue;
            visited.add(neighbor);
            // x / y = x / neighbor * neighbor/y
            double d = divide(neighbor, y, visited);
            if (d > 0)
                return d * g.get(x).get(neighbor);
        }
        return -1.0;
    }
}
