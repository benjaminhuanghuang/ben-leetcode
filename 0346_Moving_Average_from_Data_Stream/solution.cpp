

/*
定义了一个MovingAverage类，里面可以存固定个数字，然后我们每次读入一个数字，如果加上这个数字后总个数大于限制的个数，
那么我们移除最早进入的数字，然后返回更新后的平均数，

这种先进先出的特性最适合使用队列queue来做，而且我们还需要一个double型的变量sum来记录当前所有数字之和，
这样有新数字进入后，如果没有超出限制个数，则sum加上这个数字，
如果超出了，那么sum先减去最早的数字，再加上这个数字，然后返回sum除以queue的个数即可
*/

#include <queue>

using namespace std;

class MovingAverage
{
public:
  MovingAverage(int size)
  {
    this->size = size;
    sum = 0;
  }

  double next(int val)
  {
    if (q.size() >= size)
    {
      sum -= q.front();
      q.pop();
    }
    q.push(val);
    sum += val;
    return sum / q.size();
  }

private:
  queue<int> q;
  int size;
  double sum;
};