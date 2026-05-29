/*
 * Problem: Minimum Element After Replacement With Digit Sum (LeetCode 3300)
 * Concept: Array Iteration, Math (Digit Manipulation)
 * Time Complexity: O(N) - Where N is the number of elements in the array
 * Space Complexity: O(1) - Constant space used
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minElement(vector<int>& nums) {
        int mi = INT_MAX;
        for (int num : nums) {
            int sum = 0;
            while (num > 0) {
                int r = num % 10;
                sum += r;
                num /= 10;
            }
            if (mi > sum) {
                mi = sum;
            }
        }
        return mi;
    }
};