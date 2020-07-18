/*
284. Peeking Iterator

Level: Medium

https://leetcode.com/problems/peeking-iterator
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

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 */
struct Iterator
{
	struct Data;
	Data *data;
	Iterator(const vector<int> &nums);
	Iterator(const Iterator &iter);

	// Returns the next element in the iteration.
	int next();

	// Returns true if the iteration has more elements.
	bool hasNext() const;
};

class PeekingIterator : public Iterator
{
private:
	//设一个 peeked 的flag 同时 保存 peeked 过得值.  如果已经peeked过了, next()直接返回保存的值即可.
	bool peeked;
	int peekVal;

public:
	PeekingIterator(const vector<int> &nums) : Iterator(nums)
	{
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.
		peeked = false;
	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek()
	{
		if (peeked)
			return peekVal;

		peeked = true;
		peekVal = Iterator::next();

		return peekVal;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next()
	{
		if (!peeked)
			peekVal = Iterator::next();
		peeked = false;
		return peekVal;
	}

	bool hasNext() const
	{
		 return Iterator::hasNext() || peeked;
	}
};