/*
534. Design TinyURL
How would you design a URL shortening service that is similar to TinyURL?

Background:
TinyURL is a URL shortening service where you enter a URL such as 
https://leetcode.com/problems/design-tinyurl and it returns a short URL 
such as http://tinyurl.com/4e9iAk.

Requirements:
For instance, "http://tinyurl.com/4e9iAk" is the tiny url for the page 
"https://leetcode.com/problems/design-tinyurl". 
The identifier (the highlighted part) can be any string with 6 alphanumeric characters 
containing 0-9, a-z, A-Z.
Each shortened URL must be unique; that is, no two different URLs can be shortened to the same URL.
Note about Questions:
Below are just a small subset of questions to get you started. In real world, there could be many 
follow ups and questions possible and the discussion is open-ended (No one true or correct way to 
solve a problem). If you have more ideas or questions, please ask in Discuss and we may compile 
it here!

Questions:
How many unique identifiers possible? Will you run out of unique URLs?
Should the identifier be increment or not? Which is easier to design? Pros and cons?
Mapping an identifier to an URL and its reversal - Does this problem ring a bell to you?
How do you store the URLs? Does a simple flat file database work?
What is the bottleneck of the system? Is it read-heavy or write-heavy?
Estimate the maximum number of URLs a single machine can store.
Estimate the maximum number of queries per second (QPS) for decoding a shortened URL in a single 
machine.
How would you scale the service? For example, a viral link which is shared in social media could 
result in a peak QPS at a moment's notice.
How could you handle redundancy? i,e, if a server is down, how could you ensure the service is 
still operational?


https://segmentfault.com/a/1190000006140476
62^6=570
sixty two to the sixth power. 
The sixth power of sixty two.

*/

using System;
using System.Text;
using System.Collections.Generic;

public class URLService
{
    Dictionary<string, int> ltos;
    Dictionary<int, string> stol;
    static int COUNTER;
    string elements;
    URLService()
    {
        ltos = new Dictionary<string, int>();
        stol = new Dictionary<int, string>();
        COUNTER = 1;
        elements = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }
    public string longToShort(string url)
    {
        string shorturl = base10ToBase62(COUNTER);
        ltos.Add(url, COUNTER);
        stol.Add(COUNTER, url);
        COUNTER++;
        return "http://tiny.url/" + shorturl;
    }
    public string shortToLong(string url)
    {
        url = url.Substring("http://tiny.url/".Length);
        int n = base62ToBase10(url);
        return stol[n];
    }

    public int base62ToBase10(string s)
    {
        int n = 0;
        for (int i = 0; i < s.Length; i++)
        {
            n = n * 62 + CharToInt(s[i]);
        }
        return n;

    }
    public int CharToInt(char c)
    {
        if (c >= '0' && c <= '9')
            return c - '0';
        if (c >= 'a' && c <= 'z')
        {
            return c - 'a' + 10;
        }
        if (c >= 'A' && c <= 'Z')
        {
            return c - 'A' + 36;
        }
        return -1;
    }
    public string base10ToBase62(int n)
    {
        StringBuilder sb = new StringBuilder();
        while (n != 0)
        {
            sb.Insert(0, elements[n % 62]);
            n /= 62;
        }
        while (sb.Length != 6)
        {
            sb.Insert(0, '0');
        }
        return sb.ToString();
    }
}