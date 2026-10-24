/*
332. Reconstruct Itinerary

Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], 
reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. 

Thus, the itinerary must begin with JFK.

Note:
If there are multiple valid itineraries, you should return the itinerary that has the smallest 
lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller 
lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.

Example 1:
    tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
    Return ["JFK", "MUC", "LHR", "SFO", "SJC"].

Example 2:
    tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
    Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
    Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.
*/

/*
http://www.cnblogs.com/EdwardLiu/p/5184961.html

*/
using System.Collections.Generic;

public class Solution332
{
    /*
        http://www.voidcn.com/blog/bearkino/article/p-5037524.html
        1. 采用字典，departure - [ arrival ]
        2. dfs 深度搜索，递归调用
        3. trace back 回溯，增加判断如果不可能的就恢复数据，然后返回继续dfs搜索
    */
    public IList<string> FindItinerary(string[,] tickets)
    {
        if (tickets == null || tickets.GetLength(0) == 0)
            return new List<string>();
        var result = new List<string>();
        result.Add("JFK");
        var dep_arrs_dict = new Dictionary<string, List<string>>();
        for (int i = 0; i < tickets.GetLength(0); i++)
        {
            if (!dep_arrs_dict.ContainsKey(tickets[i, 0]))
                dep_arrs_dict.Add(tickets[i, 0], new List<string>());
            dep_arrs_dict[tickets[i, 0]].Add(tickets[i, 1]);
        }

        DFSHelper(dep_arrs_dict, "JFK", result, tickets.GetLength(0));
        return result;
    }

    public IList<string> DFSHelper(Dictionary<string, List<string>> dict, string departure, List<string> result, int flights)
    {
        if (result.Count == flights + 1)
            return result;

        if (dict.ContainsKey(departure))
        {
            List<string> destinations = new List<string>(dict[departure]);
            destinations.Sort();

            foreach (string dest in destinations)
            {
                dict[departure].Remove(dest);
                result.Add(dest);

                var valid = DFSHelper(dict, dest, result, flights);
                if (valid != null && valid.Count > 0)
                    return valid;

                result.RemoveAt(result.Count - 1);
                dict[departure].Add(dest);
            }
        }
        return null;
    }
}

/*
    var input = new string[,]{{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};

    var s = new Solution332();
    var result = s.FindItinerary(input);  

    Console.WriteLine(result);
*/
