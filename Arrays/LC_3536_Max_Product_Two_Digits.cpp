/*
 * Problem: Maximum Product of Two Digits (LeetCode 3536)
 * Concept: Math / Digit Extraction / Greedy
 * Time Complexity: O(d) // where d is the number of digits in n
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(int n) {
        int max1 = 0; 
        int max2 = 0; 
        
        while (n > 0) {
            int digit = n % 10;
            
            if (digit > max1) {
                max2 = max1;  
                max1 = digit; 
            } 
            else if (digit > max2) {
                max2 = digit; 
            }
            
            n /= 10;
        }
        
        return max1 * max2;
    }
};