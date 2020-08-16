/*
1024. Video Stitching 

Level: Medium

https://leetcode.com/problems/video-stitching/
*/

#include <vector>
#include <algorithm>

using namespace std;

/*
https://www.youtube.com/watch?v=tEx3z4L7F-c
*/
class Solution
{
public:
  int videoStitching(vector<vector<int>> &clips, int T)
  {
    // sort by start time and end time
    sort(clips.begin(), clips.end(), [](vector<int>& clipA, vector<int> &clipB){
      return clipA[0] == clipB[0] ? clipA[1] <= clipB[1] : clipA[0] < clipB[0];
    });

    int res = 0;
    int cur_end = -1;      // 已经加入结果集的clip所形成的end, 表示当前已经覆盖到的区域的最右边距离
    int potential_end = 0; // 表示在剩下的线段中找到的所有左端点小于等于当前已经覆盖到的区域的右端点的线段中，不断更新最右边的距离
    
    for (auto clip : clips)
    {
      if (potential_end >= T || clip[0] > potential_end)
      {
        break;
      }
      if (clip[0] > cur_end)
      { //当前的这个clip不可能被选取，需要更新cur_end，并让res++
        res++;
        cur_end = potential_end;
      }
      // clip[0] <= cur_end
      potential_end = max(potential_end, clip[1]);
    }
    return potential_end >= T ? res : -1;
  }
};