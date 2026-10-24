/*
381. Insert Delete GetRandom O(1) - Duplicates allowed

https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
*/
#include <random>
#include <vector>
#include <unordered_map>
using namespace std;
/*
http://zxi.mytechroad.com/blog/hashtable/leetcode-381-insert-delete-getrandom-o1-duplicates-allowed/
*/
class RandomizedCollection
{
public:
  /** Initialize your data structure here. */
  RandomizedCollection() {}

  /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
  bool insert(int val)
  {
    m_[val].push_back(vals_.size());
    vals_.emplace_back(val, m_[val].size() - 1);
    return m_[val].size() == 1u;
  }

  /** Removes a value from the collection. Returns true if the collection contained the specified element. */
  bool remove(int val)
  {
    if (!m_.count(val))
      return false;
    int index_to_evict = m_[val].back();
    const auto &last_entry = vals_.back();

    // Update indexs
    m_[last_entry.first][last_entry.second] = index_to_evict;

    // Swap vals
    swap(vals_.back(), vals_[index_to_evict]);

    // Clenup
    vals_.pop_back();
    m_[val].pop_back();
    if (m_[val].empty())
      m_.erase(val);

    return true;
  }

  /** Get a random element from the collection. */
  int getRandom()
  {
    return vals_[rand() % vals_.size()].first;
  }

private:
  // val -> indices array: indices in vals_
  unordered_map<int, vector<int>> m_;
  // {val, index in the indices array}
  vector<pair<int, int>> vals_;
};