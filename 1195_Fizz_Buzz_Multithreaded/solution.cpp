/*
1195. Fizz Buzz Multithreaded

Level: Medium

https://leetcode.com/problems/fizz-buzz-multithreaded/
*/

/*
  Solution:
  4 Semaphores 
  https://zxi.mytechroad.com/blog/concurrent/leetcode-1195-fizz-buzz-multithreaded/
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <mutex>

using namespace std;

class Semaphore
{
public:
  Semaphore(int count = 0) : count_(count) {}

  inline void notify()
  {
    unique_lock<std::mutex> lock(mtx_);
    count_++;
    cv_.notify_one();
  }

  inline void wait()
  {
    unique_lock<std::mutex> lock(mtx_);
    while (count_ == 0)
      cv_.wait(lock);
    count_--;
  }

private:
  mutex mtx_;
  condition_variable cv_;
  int count_;
};

class FizzBuzz
{
private:
  int n;
  Semaphore sn;
  Semaphore s3;
  Semaphore s5;
  Semaphore s15;

public:
  FizzBuzz(int n) : n(n), sn(1), s3(0), s5(0), s15(0) {}

  // printFizz() outputs "fizz".
  void fizz(function<void()> printFizz)
  {
    for (int i = 3; i <= n; i += 3)
    {
      if (i % 5 == 0)
        continue;
      s3.wait();
      printFizz();
      sn.notify();
    }
  }
  // printBuzz() outputs "buzz".
  void buzz(function<void()> printBuzz)
  {
    for (int i = 5; i <= n; i += 5)
    {
      if (i % 3 == 0)
        continue;
      s5.wait();
      printBuzz();
      sn.notify();
    }
  }

  // printFizzBuzz() outputs "fizzbuzz".
  void fizzbuzz(function<void()> printFizzBuzz)
  {
    for (int i = 15; i <= n; i += 15)
    {
      s15.wait();
      printFizzBuzz();
      sn.notify();
    }
  }
   // printNumber(x) outputs "x", where x is an integer.
  void number(function<void(int)> printNumber)
  {
    for (int i = 1; i <= n; ++i)
      if (i % 15 == 0)
      {
        s15.notify();
        sn.wait();
      }
      else if (i % 5 == 0)
      {
        s5.notify();
        sn.wait();
      }
      else if (i % 3 == 0)
      {
        s3.notify();
        sn.wait();
      }
      else
      {
        printNumber(i);
      }
  }
};