/*
1114. Print in Order
https://leetcode.com/problems/print-in-order/

The same instance of Foo will be passed to three different threads. 
Thread A will call one(), thread B will call two(), and thread C will call three(). 

Design a mechanism and modify the program to ensure that two() is executed after one(), and three() is executed after two().


 */


/*
A std::condition_variable has a method wait(), which blocks, when it is called by a thread. 
The condition variable is kept blocked until it is released by another thread. 
The release works via the method notify_one() or the notify_all method. The key difference between the two methods is that notify_one will only wake up a single waiting thread while notify_all will wake up all the waiting threads at once.

 */
#include <thread>
#include <mutex>

using namespace std;

class Foo {
private:
    bool firstDone, secondDone;
    mutex m;
    condition_variable cv1, cv2;
public:
    Foo() {
        firstDone = false;
        secondDone = false;
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        firstDone = true;
        cv1.notify_one();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lk(m);
        cv1.wait(lk, [this]{return firstDone;});
        //lk.unlock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        secondDone = true;
        cv2.notify_one();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lk(m);
        cv2.wait(lk, [this]{return secondDone;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};