/*
 * Problem: Find Minimum Operations to Make All Elements Divisible by Three (LeetCode 3190)
 * Concept: Array, Math
 * TC: O(N) - Single pass through the array.
 * SC: O(1) - Constant space used.
 */

#include <vector>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;
        for (int num : nums) {
           
            if (num % 3 != 0) {
                ops++;
            }
        }
        return ops;
    }
};