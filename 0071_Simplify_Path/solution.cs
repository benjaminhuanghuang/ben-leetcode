/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"


Test Case:
    /...
    /a/./b///../c/../././../d/..//../e/./f/./g/././//.//h///././/..///
*/

using System;
using System.Text;
using System.Linq;
using System.Collections.Generic;

public class Solution071 {
    public string SimplifyPath(string path) {
        var stack = new Stack<string>();
        string[] dirs = path.Split(new []{'/'}, StringSplitOptions.RemoveEmptyEntries);
        for (int i =0 ; i < dirs.Length; i++)
        {
            /*
            if(dirs[i]==".." && stack.Count > 0) // Wrong ! cause pushing ".." to stack
                stack.Pop();
            else if(dirs[i]==".")
                continue;
            else
                stack.Push(dirs[i]);
            */
            if(dirs[i]==".")
                continue;
            if(dirs[i]=="..")
            {
                if(stack.Count > 0)
                    stack.Pop();
            }
            else
                stack.Push(dirs[i]);     
        }
        if (stack.Count == 0)
            return "/";
        StringBuilder sb = new StringBuilder();
        while(stack.Count > 0)
        {
            string dir = stack.Pop(); 
            sb.Insert(0, dir);
            sb.Insert(0, "/");        
        }
        return sb.ToString();
    }

    public string SimplifyPath_2(string path)
    {
        var stack = new Stack<string>();
        string[] tokens = path.Split(new []{'/'}, StringSplitOptions.RemoveEmptyEntries);
        foreach (var token in tokens)
        {
            if (token.Equals("."))
            {
                continue;
            }
            if(token.Equals(".."))
            {
                if (stack.Count > 0)
                {
                    stack.Pop();
                }
            }
            else
            {
                stack.Push(token);
            }
        }
        return stack.Count >0 ? "/" + stack.Aggregate((current, str) => str + "/" + current) : "/";
    }
}   