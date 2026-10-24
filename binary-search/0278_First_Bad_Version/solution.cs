public class Solution278 {
    public int FirstBadVersion(int n) {
        int left = 1, right = n;
        while(left < right)
        {
            int mid = left + (right-left) /2;
            if(this.IsBadVersion(mid))
            {
                right = mid;
            }
            else
            {
                left = mid +1;
            }
        }
        return right;
    }


    bool IsBadVersion(int version)
    {
        return false;
    }
}
