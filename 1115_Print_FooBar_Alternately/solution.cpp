/*
1115. Print FooBar Alternately

https://leetcode.com/problems/print-foobar-alternately/

*/

/*
A std::condition_variable has a method wait(), which blocks, when it is called by a thread. 
The condition variable is kept blocked until it is released by another thread. 
The release works via the method notify_one() or the notify_all method. The key difference between the two methods is that notify_one will only wake up a single waiting thread while notify_all will wake up all the waiting threads at once.

 */
#include <thread>
#include <mutex>
#include <functional>

using namespace std;
/*
https://www.youtube.com/watch?v=VoOJdqHe8bE&t=473s


*/
class FooBar
{
private:
    int n;
    mutex m1;
    mutex m2;

public:
    FooBar(int n)
    {
        this->n = n;
        m2.lock();
    }

    void foo(function<void()> printFoo)
    {

        for (int i = 0; i < n; i++)
        {
            m1.lock();
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            m2.unlock();
        }
    }

    void bar(function<void()> printBar)
    {

        for (int i = 0; i < n; i++)
        {
            m2.lock();
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            m1.unlock();
        }
    }
};