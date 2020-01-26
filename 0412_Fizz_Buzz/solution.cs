/*
412. Fizz Buzz

Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of 
five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
*/

using System.Collections.Generic;

public class Solution412 {
    public IList<string> FizzBuzz(int n) {
        List<string> res = new List<string>();
        for(int i=0; i< n; i++)
        {
            int num = i + 1;
            if (num % 15 == 0)
                res.Add("FizzBuzz");
            else if (num % 3 ==0)
                res.Add("Fizz");
            else if (num % 5 == 0)
                res.Add("Buzz");
            else
                res.Add(num.ToString());
        }       
        return res;
    }
}