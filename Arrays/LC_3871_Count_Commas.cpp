/*
 * Problem: Count Commas (LeetCode 3871)
 * Concept: Math
 * TC: O(log10(n)) - We multiply the limit by 1000 for every iteration, making the step count logarithmic.
 * SC: O(1) - Constant space used.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    long long countCommas(long long n) {
        long long limit = 1000, total = 0;
        
        while (limit <= n) {
            total += (n - limit + 1);
            limit *= 1000;
        }
        
        return total;
    }
};