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

## Direction
874. Walking Robot Simulation

```
  // north, west, south, east
  vector<vector<int>> dirs{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
  // OR
  vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  for (auto d : dirs){
    
  }
```
- 892. Surface Area of 3D Shapes
```
vector<int> dirs{0, -1, 0, 1, 0};

for (int i = 0; i < 4; ++i)
{
  int tx = x + dirs[i];
  int ty = y + dirs[i + 1];
  if (tx < 0 || tx >= m || ty < 0 || ty >= n || grid[ty][tx] != 0)
    continue;
  grid[ty][tx] = 2;
  q.push(ty * 100 + tx);
}
```

## Split string
```
  stringstream sb(B);
  string word;
  while (sb >> word)
  {
    map[word]++;
  }
```

## If tow numbers have same sign
```
  bool sign = !((dividend > 0) ^ (divisor > 0));
```