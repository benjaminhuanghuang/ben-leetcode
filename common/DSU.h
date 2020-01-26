/*
Disjoint Set Union
https://www.youtube.com/watch?v=VJnUwsE4fWA

Find O(1) with optimization, O(N) without optimization
Union O(1)
Space O(N)
*/

#include <vector>
#include <numeric>

using namespace std;

class DSU
{
public:
  DSU(int size) : size_(size), parent_(size), rank_(size)
  {
    //iota(begin(parent_), end(parent_), 0);
    for(int i=0; i < parent_.size(); i++)
    {
      parent_[i] = i;
    }
  }

  /*
    find the root / cluster id of node,
    set parent of n to root
  */
  int Find(int n)
  {
    if (parent_[n] != n)
      parent_[n] = Find(parent_[n]);  // path compression during Find
    return parent_[n];
  }

  bool Union(int x, int y)
  {
    int root_x = Find(x);
    int root_y = Find(y);
    if (root_x == root_y)
      return false;
      
    // root_x has bigger rank
    if (rank_[root_y] > rank_[root_x])
      swap(root_x, root_y);
    else if (rank_[root_y] == rank_[root_x])
      ++rank_[root_x];
    parent_[root_y] = root_x;    // merge y to x, x has bigger rank
    --size_;
    return true;
  }

  int Size() const
  {
    return size_;
  }

private:
  int size_;
  vector<int> rank_;
  vector<int> parent_;
};