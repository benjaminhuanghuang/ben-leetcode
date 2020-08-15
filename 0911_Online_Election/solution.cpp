/*
911. Online Election

Level: Medium

https://leetcode.com/problems/online-election
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;


class TopVotedCandidate
{
  vector<int> lead;
  vector<int> times_;
public:
  TopVotedCandidate(vector<int> &persons, vector<int> &times)
  {
    vector<pair<int, int>> q;
    for(int i =0;i < persons.size(); i++)
    {
      q.push_back({times[i], persons[i]});
    }
    sort(q.begin(), q.end());
    sort(times.begin(), times.end());
    times_ = times;
    int leadPerson;
    int leadVotes = 0;
    unordered_map<int, int> Map; // person->votes

    for(int i =0;i < q.size(); i++)
    {
      Map[q[i].second] ++;
      if(Map[q[i].second] >= leadVotes){
        leadVotes = Map[q[i].second];
        leadPerson = q[i].second;
      }
      lead.push_back(leadPerson);
    }
  }

  int q(int t)
  {
    auto iter = upper_bound(times_.begin(), times_.end(), t);
    int i = iter - times_.begin() -1;
    return lead[i];
  }
};



/*
  Solution: 
  Compute the leads for each t in times using a hash table.

    binary search the upper bound of t, and return the lead of previous entry.

    Time complexity: Constructor O(n), Query: O(logn)

    Space complexity: O(n)
*/

class TopVotedCandidate
{
public:
  TopVotedCandidate(vector<int> &persons, vector<int> &times)
  {
    vector<int> votes(persons.size() + 1);
    int last_lead = persons.front();
    for (int i = 0; i < persons.size(); ++i)
    {
      if (++votes[persons[i]] >= votes[last_lead])
        last_lead = persons[i];
      leads_[times[i]] = last_lead;
    }
  }

  int q(int t)
  {
    return prev(leads_.upper_bound(t))->second;
  }

private:
  map<int, int> leads_; // time -> lead
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */