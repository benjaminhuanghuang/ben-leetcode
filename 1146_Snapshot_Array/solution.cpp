/*
1146. Snapshot Array

Level: Medium

https://leetcode.com/problems/snapshot-array
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


/*
  Solution: 
  https://zxi.mytechroad.com/blog/data-structure/leetcode-1146-snapshot-array/
  
  array, 
  snap() 对array 生成快照， 
  brute-force 解法会每次 snap() 保存 整个array，这样会有大量的冗余操作

  Use a vector to store maps, one map per element. vals_[index]<snap_id, value>

  The map stores {snap_id -> val}, use upper_bound to find the first version > snap_id and use previous version’s value.
*/

class SnapshotArray {
public:
  SnapshotArray(int length): id_(0), vals_(length) {}
 
  void set(int index, int val) {
    vals_[index][id_] = val;
  }
  
  // id = snap times - 1
  int snap() { return id_++; }
 
  int get(int index, int snap_id) const {
    auto it = vals_[index].upper_bound(snap_id);
    if (it == begin(vals_[index])) return 0;
    return prev(it)->second;
  }
private:
  int id_;
  vector<map<int, int>> vals_;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */