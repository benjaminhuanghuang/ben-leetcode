/*
1396. Design Underground System

Level: Medium

https://leetcode.com/problems/design-underground-system
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class UndergroundSystem
{
public:
  UndergroundSystem()
  {
  }

  void checkIn(int id, string stationName, int t)
  {
    in_report[id] = make_pair(stationName, t);
  }

  void checkOut(int id, string stationName, int t)
  {
    pair<string, int> in_station_time = in_report[id];   // in station and time
    string in_station = in_station_time.first;

    unordered_map<string, vector<int>> out_station_time = history[in_station];
    out_station_time[stationName].push_back(t - in_station_time.second);
    history[in_station] = out_station_time;
  }

  double getAverageTime(string startStation, string endStation)
  {
    unordered_map<string, vector<int>> out_station_time = history[startStation];
    int sum = std::accumulate(out_station_time[endStation].begin(), out_station_time[endStation].end(), 0);
    return sum / ((double)out_station_time[endStation].size());
  }

private:
  // id - start station and time
  unordered_map<int, pair<string, int>> in_report;
  // start station - 
  unordered_map<string, unordered_map<string, vector<int>>> history;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */