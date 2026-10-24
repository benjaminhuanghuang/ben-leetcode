/*
1200. Minimum Absolute Difference

Level: Easy

https://leetcode.com/problems/minimum-absolute-difference
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class Solution
{
public:
  vector<vector<int>> minimumAbsDifference(vector<int> &arr)
  {
    sort(begin(arr), end(arr));
    vector<vector<int>> ans;
    int best = INT_MAX;
    for (int i = 1; i < arr.size(); ++i)
    {
      int distance = abs(arr[i] - arr[i - 1]);
      if (distance < best)
      {
        ans.clear();   //Importent!
        best = distance;
      }
      if (distance == best)
        ans.push_back({arr[i - 1], arr[i]});
    }
    return ans;
  }


   int minDiff(vector<int>&arr){
		int min=arr[1]-arr[0];
		for(int i=0; i<arr.size()-1; i++){
			if((arr[i+1]-arr[i])<min)
				min=arr[i+1]-arr[i];
		}
		return min; 
	 }

	 vector<vector<int>> minimumAbsDifference_naive(vector<int>& arr) {
		vector<vector<int>> out;
		sort(arr.begin(), arr.end());
		int min=minDiff(arr);

		for(int i=0; i<arr.size()-1; i++){
			int resDiff = arr[i+1]-arr[i];
			if(resDiff==min){
				vector<int> temp = {arr[i], arr[i+1]};
				out.push_back(temp);
			}
		}


		return out;

	}
};