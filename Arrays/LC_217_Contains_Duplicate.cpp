/*
 * Problem: Contains Duplicate (LeetCode 217)
 * Concept: Arrays / Hashing (unordered_set)
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> s(nums.begin(), nums.end());
        return s.size() < nums.size();
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1, 2, 3, 1};

    if (sol.containsDuplicate(nums))
    {
        cout << "Result: True (Duplicates found!)" << endl;
    }
    else
    {
        cout << "Result: False (No duplicates)" << endl;
    }

    return 0;
}