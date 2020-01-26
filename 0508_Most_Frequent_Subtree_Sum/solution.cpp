/*
508. Most Frequent Subtree Sum

https://leetcode.com/problems/most-frequent-subtree-sum/
 */
#include <vector>
#include <unordered_map>
using namespace std;
#include "common/TreeNode.h"

class Solution {
public:
  vector<int> findFrequentTreeSum(TreeNode* root) {
    unordered_map<int, int> freqs;
    int max_freq = -1;
    vector<int> ans;
    (void)treeSum(root, freqs, max_freq, ans);
    return ans;
  }
private:
  int treeSum(TreeNode* root, unordered_map<int, int>& freqs, int& max_freq, vector<int>& ans) {
    if (!root) return 0;
    int sum = root->val + 
              treeSum(root->left, freqs, max_freq, ans) + 
              treeSum(root->right, freqs, max_freq, ans);
    int freq = ++freqs[sum];
    if (freq > max_freq) {
      max_freq = freq;
      ans.clear();
    }
    if (freq == max_freq)
      ans.push_back(sum);
    return sum;
  }
};