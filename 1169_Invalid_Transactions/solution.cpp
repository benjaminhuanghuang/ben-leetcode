/*
1169. Invalid Transactions

Level: Medium

https://leetcode.com/problems/invalid-transactions
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
  https://www.acwing.com/solution/LeetCode/content/4185/
*/

class Trans {
public:
    int time, amount;
    string name, city;
    bool valid;

    Trans(string&& name, int time, int amount, string&& city) {
        this -> name = name;
        this -> time = time;
        this -> amount = amount;
        this -> city = city;
        this -> valid = true;
    }

    string serialization() const {
        return name + "," + to_string(time) + "," + to_string(amount) + "," + city;
    }
};

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<Trans> trans;
        for (const auto &tr: transactions) {
            auto&& t = split(tr);
            trans.emplace_back(move(t[0]), stoi(t[1]), stoi(t[2]), move(t[3]));
        }
        for (int i = 0; i < trans.size(); i++) {
            auto& ti = trans[i];
            if (ti.amount > 1000)
                ti.valid = false;
            else {
                for (int j = 0; j < trans.size(); j++) {
                    if (i == j)
                        continue;
                    const auto& tj = trans[j];
                    if (ti.name == tj.name && ti.city != tj.city
                        && abs(ti.time - tj.time) <= 60) {
                        ti.valid = false;
                        break;
                    }
                }
            }
        }

        vector<string> ans;
        for (const auto& tr: trans)
            if (!tr.valid)
                ans.push_back(tr.serialization());

        return ans;
    }

private:
    vector<string> split(const string &trans) {
        vector<string> ret;
        string cur;
        for (char c : trans) {
            if (c == ',')
                ret.push_back(move(cur));
            else
                cur += c;
        }

        ret.push_back(move(cur));
        return ret;
    }
};