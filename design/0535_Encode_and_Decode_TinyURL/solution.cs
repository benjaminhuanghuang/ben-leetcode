/*
535. Encode and Decode TinyURL

TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl 
and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode 
algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be 
decoded to the original URL.

Subscribe to see which companies asked this question.
 */
using System;
using System.Text;
using System.Collections.Generic;

public class Codec535
{
    Dictionary<string, string> long_tiny = new Dictionary<string, string>();
    Dictionary<string, string> tiny_long = new Dictionary<string, string>();
    String s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    // Encodes a URL to a shortened URL
    public string encode(string longUrl)
    {
        if (long_tiny.ContainsKey(longUrl))
        {
            return long_tiny[longUrl];
        }
        int val = long_tiny.Count + 1;
        string tinyUrl = IntToTinyUrl(val);
        long_tiny.Add(longUrl, tinyUrl);
        tiny_long.Add(tinyUrl, longUrl);
        return tinyUrl;
    }

    private int tinyUrlToInt(string shortUrl)
    {
        int val = 0;
        for (int i = 0; i < shortUrl.Length; i++)
        {
            val = val * 62 + s.IndexOf(shortUrl[i]);
        }
        return val;
    }

    private string IntToTinyUrl(int val)
    {
        StringBuilder sb = new StringBuilder();
        while (val > 0)
        {
            int remainder = val % 62;
            val /= 62;
            sb.Insert(0, s[remainder]);
        }
        return sb.ToString();
    }


    // Decodes a shortened URL to its original URL.
    public string decode(string tinyUrl)
    {
        return tiny_long[tinyUrl];
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));