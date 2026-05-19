/*
 * Problem: Fibonacci Number (LeetCode 509)
 * Concept: Recursion (Induction, Base Condition, Hypothesis)
 * Time Complexity: O(2^N) - Exponential time without Memoization
 * Space Complexity: O(N) - Maximum depth of the recursion stack
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        return fib(n - 1) + fib(n - 2);
    }
};