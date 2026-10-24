package cn.huang.leetcode;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/*
997. Find the Town Judge

In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.

There is exactly one person that satisfies properties 1 and 2.
You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.



Example 1:

Input: N = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: N = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: N = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
Example 4:

Input: N = 3, trust = [[1,2],[2,3]]
Output: -1
Example 5:

Input: N = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3


Note:

1 <= N <= 1000
trust.length <= 10000
trust[i] are all different
trust[i][0] != trust[i][1]
1 <= trust[i][0], trust[i][1] <= N
 */
public class LC_0997_FindtheTownJudge {
    /*
       https://zxi.mytechroad.com/blog/2019/02/
       Graph, Count the degree, trust is edge
       Time O(N), Space O(N)
    */
    public int findJudge(int N, int[][] trust) {
        //if (trust == null || trust.length == 0)  NO Need !!
        //     return 1;

        int[] degrees = new int[N+1];   // index from 1
        for(int[] t: trust)
        {
            --degrees[t[0]];
            ++degrees[t[1]];
        }
        for(int i =1 ;i <=N ; i++)
        {
            if(degrees[i] == N-1)
                return i;
        }
        return -1;
    }

    public int findJudge_my(int N, int[][] trust) {
        if (trust == null || trust.length == 0)
            return 1;

        int judge = -1;
        Map<Integer, Integer> count = new HashMap<>();
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < trust.length; i++) {

            int people = trust[i][0];
            set.add(people);
            if(people == judge){
                judge = -1;
            }
            int trusted = trust[i][1];
            if(!set.contains(trusted))
            {
                count.put(trusted, count.getOrDefault(trusted, 0) + 1);
                if (count.get(trusted) > count.getOrDefault(judge, 0))
                    judge = trusted;
            }
        }

        if (judge > 0 && count.get(judge) == N - 1)
            return judge;
        return -1;
    }
}


