/*
241. Different Ways to Add Parentheses


Given a string of numbers and operators, return all possible results from computing all the different 
possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
*/

using System.Collections.Generic;

public class Solution241 {
    public IList<int> DiffWaysToCompute(string input) {
        List<int> result = new List<int>();
        int len = input.Length;
        if(len == 0)
            return result;
        int val;
        if(int.TryParse(input , out val))
        {
            result.Add(val);
            return result;
        }
        for(int i=0; i < len; i++)
        {
            if(!char.IsDigit(input[i]))
            {
                var leftResult = DiffWaysToCompute(input.Substring(0, i));
                var rightResult = DiffWaysToCompute(input.Substring(i + 1));
                for ( int m =0; m < leftResult.Count; m++)
                {
                    for ( int n =0; n < rightResult.Count; n++)
                    {
                        switch(input[i]){  
                            case '+':  
                                result.Add(leftResult[m] + rightResult[n]);  
                                break;  
                            case '-':  
                                result.Add(leftResult[m] - rightResult[n]);  
                                break;  
                            case '*':  
                                result.Add(leftResult[m] * rightResult[n]);  
                                break;
                        }  
                    }
                }
            }
        }
        return result;
    }
}