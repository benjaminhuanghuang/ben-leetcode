/*
380. Insert Delete GetRandom O(1)

*/

#include <random>
#include <unordered_map>
using namespace std;

/*
http://zxi.mytechroad.com/blog/hashtable/leetcode-380-insert-delete-getrandom-o1/
Insert O(1)  hash table
Delete O(1)  hash table
GetRandom O(1) array
*/

class RandomizedSet
{
public:
  /** Initialize your data structure here. */
  RandomizedSet() {}

  /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  bool insert(int val)
  {
    if (m_.count(val))
      return false;
    m_[val] = vals_.size();
    vals_.push_back(val);
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the specified element. */
  bool remove(int val)
  {
    if (!m_.count(val))
      return false;
    int index = m_[val];
    m_[vals_.back()] = index;
    m_.erase(val);
    swap(vals_[index], vals_.back());
    vals_.pop_back();
    return true;
  }

  /** Get a random element from the set. */
  int getRandom()
  {
    int index = rand() % vals_.size();
    return vals_[index];
  }

private:
  // val -> index in the array
  unordered_map<int, int> m_;
  vector<int> vals_;
};