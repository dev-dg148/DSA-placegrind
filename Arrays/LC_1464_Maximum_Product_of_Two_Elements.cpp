/*
 * Problem: Maximum Product of Two Elements in an Array (LeetCode 1464)
 * Concept: Arrays / Two Largest Elements
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m1 = INT_MIN, m2 = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (m1 < nums[i]) {
                m2 = m1;
                m1 = nums[i];
            } else if (m2 < nums[i]) {
                m2 = nums[i];
            }
        }
        return (m1 - 1) * (m2 - 1);
    }
};