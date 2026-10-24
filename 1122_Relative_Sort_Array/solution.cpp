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