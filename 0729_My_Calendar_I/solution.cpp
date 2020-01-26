/*
729. My Calendar I

https://leetcode.com/problems/my-calendar-i/
*/
#include <vector>
#include <map>
using namespace std;

/*
https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-729-my-calendar-i/

Brute Force: O(n^2)
*/
class MyCalendar
{
public:
  MyCalendar()
  {
  }

  bool book(int start, int end)
  {
    for (const auto &event : booked_)
    {
      int s = event.first;
      int e = event.second;
      if (max(s, start) < min(e, end))
        return false;
    }
    booked_.emplace_back(start, end);
    return true;
  }

private:
  vector<pair<int, int>> booked_;
};

/*
https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-729-my-calendar-i/

Binary Search O(nlogn)
*/
class MyCalendar
{
public:
  MyCalendar()
  {
  }

  bool book(int start, int end)
  {
    auto it = booked_.lower_bound(start);
    if (it != booked_.cend() && it->first < end)
      return false;
    if (it != booked_.cbegin() && (--it)->second > start)
      return false;
    booked_[start] = end;
    return true;
  }

private:
  map<int, int> booked_;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */