/*
1024. Video Stitching [Medium]

https://leetcode.com/problems/video-stitching/
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int videoStitching(vector<vector<int>> &clips, int T)
  {
    // sort by start time and end time
    sort(clips.begin(), clips.end(), clipComparator);

    int res = 0;
    int cur_end = -1;      // 已经加入结果集的clip所形成的end
    int potential_end = 0; // 当前可能的最远端
    
    for (auto clip : clips)
    {
      if (potential_end >= T || clip[0] > potential_end)
      {
        break;
      }
      else if (clip[0] > cur_end)
      { //当前的这个clip不可能被选取，需要更新cur_end，并让res++
        res++;
        cur_end = potential_end;
      }
      potential_end = max(potential_end, clip[1]);
    }
    return potential_end >= T ? res : -1;
  }

private:
  // sort by start time and end time
  static bool clipComparator(vector<int> clipA, vector<int> clipB)
  {
    return clipA[0] == clipB[0] ? clipA[1] <= clipB[1] : clipA[0] < clipB[0];
  }
};