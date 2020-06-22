### C++ split string
```
#include <sstream> // stringstream, getline

vector<string> splitSentence(const string &text)
{
  string word;
  vector<string> words;
  stringstream ss(text);
  while (getline(ss, word, ' '))
  {
    words.push_back(word);
  }
  return words;
}
```

### isPrime
```
  bool isPrime(int x) {
    if (x < 2) return false;
    if (x == 2) return true;
    for (int i = 2; i <= sqrt(x); ++i)
      if (x % i == 0) return false;
    return true;
  }
```
### isLeap
```
  bool isLeap(int year)
  {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
  }
```


## Reverse List
```
  ListNode *prev = nullptr;
  ListNode *curr = head;

  while (curr)
  {
    ListNode *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
```

## Binary Search
- Returns the smallest m in range [l, r) such that g(m) is true.
```
  while (l < r)
  {
    int mid = (r - l) / 2 + l;
    if (isBadVersion(mid)) // mid is too big
    {
      r = mid;
    }
    else
    {
      l = mid + 1;
    }
  }
  return l;  // NOT r   
```
- Returns the smallest m in range [l, r] such that g(m) is true.
```
  while (l <= r)
  {
    int mid = (r - l) / 2 + l;
    if (isBadVersion(mid)) // mid is too big
    {
      r = mid - 1;
    }
    else
    {
      l = mid + 1;
    }
  }
  return l;  // NOT r
```