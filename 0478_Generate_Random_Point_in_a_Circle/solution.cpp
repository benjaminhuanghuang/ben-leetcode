/*
478. Generate Random Point in a Circle
https://leetcode.com/problems/generate-random-point-in-a-circle/
*/

#include <vector>
#include <random>

using namespace std;

/*
https://www.cnblogs.com/grandyang/p/9741220.html
*/
class Solution
{
public:
  Solution(double radius, double x_center, double y_center)
  {
    r = radius;
    x0 = x_center;
    y0 = y_center;
  }

  vector<double> randPoint()
  {
    double x = 0, y = 0;
    do
    {
      //-r + 2 * r * Math.random()
      x = (2 * (double)rand() / RAND_MAX - 1.0) * r;
      y = (2 * (double)rand() / RAND_MAX - 1.0) * r;

    } while (x * x + y * y > r * r);
    return {x0 + x, y0 + y};
  }

private:
  double r;
  double x0;
  double y0;
};
