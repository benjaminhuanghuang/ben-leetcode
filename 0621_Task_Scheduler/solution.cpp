/*
621. Task Scheduler

https://leetcode.com/problems/task-scheduler/
*/
#include <vector>
#include <algorithm>

using namespace std;

/*
https://zxi.mytechroad.com/blog/greedy/leetcode-621-task-scheduler/
Counting

Time complexity: O(n)
Space complexity: O(1)

https://www.cnblogs.com/grandyang/p/7098764.html
题目中规定了两个相同任务之间至少隔n个时间点，那么我们首先应该处理的出现次数最多的那个任务，先确定好这些高频任务，然后再来安排那些低频任务。如果任务F的出现频率最高，为k次，那么我们用n个空位将每两个F分隔开，然后我们按顺序加入其他低频的任务，来看一个例子：

AAAABBBEEFFGG 3

我们发现任务A出现了4次，频率最高，于是我们在每个A中间加入三个空位，如下：

A---A---A---A

AB--AB--AB--A   (加入B)

ABE-ABE-AB--A   (加入E)

ABEFABE-ABF-A   (加入F，每次尽可能填满或者是均匀填充)

ABEFABEGABFGA   (加入G)

再来看一个例子：

ACCCEEE 2

我们发现任务C和E都出现了三次，那么我们就将CE看作一个整体，在中间加入一个位置即可：

CE-CE-CE

CEACE-CE   (加入A)

注意最后面那个idle不能省略，不然就不满足相同两个任务之间要隔2个时间点了。


https://www.youtube.com/watch?v=YCD_iYxyXoo

*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);        
        for (const char task : tasks) 
            ++count[task - 'A'];

        const int max_count = *max_element(count.begin(), count.end());   // 最大频率
        size_t ans = (max_count - 1) * (n + 1); 

        // 和 A频率一样多的task
        ans += count_if(count.begin(), count.end(),
                        [max_count](int c){ return c == max_count; });
        return max(tasks.size(), ans);
    }
};