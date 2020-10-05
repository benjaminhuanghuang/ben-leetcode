
/*

设计一个记录系统每次接受信息并保存时间戳，然后让我们打印出该消息，前提是最近10秒内没有打印出这个消息。
用哈希表来做，建立消息和时间戳之间的映射，
如果某个消息不再哈希表表，我们建立其和时间戳的映射，并返回true。
如果应经在哈希表里了，我们看当前时间戳是否比哈希表中保存的时间戳大10，如果是，更新哈希表，并返回true，
反之返回false：
 */
#include <string>
#include <unordered_map>

using namespace std;

class Logger
{
public:
  Logger() {}

  bool shouldPrintMessage(int timestamp, string message)
  {
    if (!m.count(message))
    {
      m[message] = timestamp;
      return true;
    }
    if (timestamp - m[message] >= 10)
    {
      m[message] = timestamp;
      return true;
    }
    return false;
  }

private:
  unordered_map<string, int> m;
};