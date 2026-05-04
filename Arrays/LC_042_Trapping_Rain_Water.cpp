/*
 * Problem: Trapping Rain Water (LeetCode 42 - Hard)
 * Concept: Arrays / Two-Pointer Approach
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int leftmax = 0, rightmax = 0, total = 0;
        
        while (l <= r) {
            if (height[l] <= height[r]) {
                if (height[l] >= leftmax) {
                    leftmax = height[l];
                } else {
                    total += (leftmax - height[l]);
                }
                l++;
            } else {
                if (height[r] >= rightmax) {
                    rightmax = height[r];
                } else {
                    total += (rightmax - height[r]);
                }
                r--;
            }
        }
        return total;
    }
};