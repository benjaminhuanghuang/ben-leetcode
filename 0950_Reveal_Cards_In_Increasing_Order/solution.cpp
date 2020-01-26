/*
950. Reveal Cards In Increasing Order
https://leetcode.com/problems/reveal-cards-in-increasing-order/
*/
#include <vector>
#include <queue>

using namespace std;

/*
对一堆面朝下的牌进行如下操作：

    把最上面的牌翻开
    如果还有牌，把最上面的牌放到最下面
    如果还有牌，重复1和2
问初始状况如何排列牌，才能使得翻开牌的顺序是有序的。

https://redtongue.coding.me/2018/12/02/950-Reveal-Cards-In-Increasing-Order/
我们可以用输出来反推输入，输出可以看成是一个队列,记为queue，最后入队的是最大值，最先入队的是最小值。
从输入到输出的逻辑是先把deck的第一个元素放入queue，然后第二个元素放入deck的最后；
那么从输出反推的输入的逻辑就是先把deck的最后一个元素放入到deck的第一个位置，然后再把queue的最后一个元素放入deck。
*/
class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        int n = deck.size();
        
        queue<int> q; // ordered cards
        for (int i = 0; i < n; i++)
            q.push(i);
        
        int ord2rev[n];
        for (int i = 0; i < n; i++)
        {
            int x = q.front();
            q.pop();
            ord2rev[x] = i;
            if (!q.empty())
            {
                x = q.front();
                q.pop();
                q.push(x);
            }
        }
        // sort
        sort(deck.begin(), deck.end());
        // apply reversed mapping
        vector<int> ans;
        for (int i = 0; i < n; i++)
            ans.push_back(deck[ord2rev[i]]);
        return ans;
    }
};