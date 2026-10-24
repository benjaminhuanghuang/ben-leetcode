package cn.huang.leetcode;

import java.util.*;

/*
911. Online Election

In an election, the i-th vote was cast for persons[i] at time times[i].

Now, we would like to implement the following query function: TopVotedCandidate.q(int t) will return the number of
the person that was leading the election at time t.

Votes cast at time t will moves towards our query.  In the case of a tie, the most recent vote (among tied candidates) wins.


Example 1:

Input: ["TopVotedCandidate","q","q","q","q","q","q"], [[[0,1,1,0,0,1,0],[0,5,10,15,20,25,30]],[3],[12],[25],[15],[24],[8]]
Output: [null,0,1,1,0,0,1]
Explanation:
At time 3, the votes are [0], and 0 is leading.
At time 12, the votes are [0,1,1], and 1 is leading.
At time 25, the votes are [0,1,1,0,0,1], and 1 is leading (as ties go to the most recent vote.)
This continues for 3 more queries at time 15, 24, and 8.



Note:

    1 <= persons.length = times.length <= 5000
    0 <= persons[i] <= persons.length
    times is a strictly increasing array with all elements in [0, 10^9].
    TopVotedCandidate.q is called at most 10000 times per test case.
    TopVotedCandidate.q(int t) is always called with t >= times[0].


 */
public class LC_0911_OnlineElection {
    class TopVotedCandidate {
        private TreeMap<Integer, Integer> map = new TreeMap<>();

        public TopVotedCandidate(int[] persons, int[] times) {
            //count each person's votes
            HashMap<Integer, Integer> count = new HashMap<>();
            int highestCount = 0, highestPerson = 0;

            for (int i = 0; i < persons.length; i++) {
                int person = persons[i];
                count.put(person, count.getOrDefault(person, 0) + 1);
                if (count.get(person) >= highestCount) {
                    highestCount = count.get(person);
                    highestPerson = person;
                }
                map.put(times[i], highestPerson);
            }
        }

        /*
        return the number of the person that was leading the election at time t.
         */
        public int q(int t) {
            // floorKey return the greatest key less than or equal to the given key, or null if there is no such key
            return map.get(map.floorKey(t));
        }
    }

    class TopVotedCandidate2 {
        Map<Integer, Integer> m = new HashMap<>();
        int[] time;

        public TopVotedCandidate2(int[] persons, int[] times) {
            int n = persons.length, lead = -1;
            Map<Integer, Integer> count = new HashMap<>();
            time = times;
            for (int i = 0; i < n; ++i) {
                count.put(persons[i], count.getOrDefault(persons[i], 0) + 1);
                if (i == 0 || count.get(persons[i]) >= count.get(lead))
                    lead = persons[i];
                m.put(times[i], lead);
            }
        }

        public int q(int t) {
            int i = Arrays.binarySearch(time, t);
            return i < 0 ? m.get(time[-i - 2]) : m.get(time[i]);
        }
    }
}
