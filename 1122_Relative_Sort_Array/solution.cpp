/*
1122. Relative Sort Array

Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.  
Elements that don't appear in arr2 should be placed at the end of arr1 in ascending order.

 

Example 1:

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]

 */
# include <vector>
# include <unordered_map>

using namespace std;
/*
  My solution
 */
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> counter;
        vector<int> notInArra2;
        for(int i : arr2)
        {
          counter[i] = 0;
        }
        for(int i : arr1)
        {
          if(counter.count(i))
          {
            counter[i]++;
          }
          else{
            notInArra2.push_back(i);
          }
        }
        vector<int> ans;
        for(int num: arr2)
        {
            for(int i=0 ; i <counter[num]; i++)
              ans.push_back(num);
        }
        sort(notInArra2.begin(), notInArra2.end());
        for(int num: notInArra2)
        {
            ans.push_back(num);
        }
        return ans;
    }
};