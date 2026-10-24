public class Solution413 {
    public int NumberOfArithmeticSlices(int[] A) {
        int sum=0,count=1;
        if(A.Length < 3) 
            return 0;
        for(int i=1; i< A.Length-1 ; i++)
        {
            if(A[i]-A[i-1] == A[i+1]-A[i])   
                sum += (count++);
            else
                count = 1;
        }
        return sum;
    }
}

