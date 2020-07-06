/*
1116. Print Zero Even Odd

https://leetcode.com/problems/print-zero-even-odd/
*/

/*
A std::condition_variable has a method wait(), which blocks, when it is called by a thread. 
The condition variable is kept blocked until it is released by another thread. 
The release works via the method notify_one() or the notify_all method. The key difference between the two methods is that notify_one will only wake up a single waiting thread while notify_all will wake up all the waiting threads at once.

 */
#include <thread>
#include <mutex>

using namespace std;
/*
https://www.youtube.com/watch?v=VoOJdqHe8bE&t=473s


*/

class ZeroEvenOdd
{
private:
  int n;
  mutex m_zero, m_odd, m_even;

public:
  ZeroEvenOdd(int n)
  {
    this->n = n;
    m_odd.lock();
    m_even.lock();
  }

  // printNumber(x) outputs "x", where x is an integer.
  void zero(function<void(int)> printNumber)
  {
    for (int i = 0; i < n; ++i)
    {
      m_zero.lock();
      printNumber(0);
      if (i & 1)
      {
        m_odd.unlock();
      }
      else
      {
        m_even.unlock();
      }
    }
  }

  void even(function<void(int)> printNumber)
  {
    for (int i = 2; i <= n; i += 2)
    {
      m_odd.lock();
      printNumber(i);
      m_zero.unlock();
    }
  }

  void odd(function<void(int)> printNumber)
  {
    for (int i = 1; i <= n; i += 2)
    {
      m_even.lock();
      printNumber(i);
      m_zero.unlock();
    }
  }
};