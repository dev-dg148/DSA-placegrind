/*
 * Problem: Left and Right Sum Differences (LeetCode 2574)
 * Concept: Prefix Sum Optimization (Sliding Concept)
 * Time Complexity: O(N) - Two linear passes over the array
 * Space Complexity: O(1) - Modifying the array in-place without extra space
 */

#include <iostream>
#include <vector>
#include <cmath> 

using namespace std; 

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = 0;
        
        
        for (int x : nums) {
            rightSum += x;
        }
        
       
        for (int i = 0; i < nums.size(); i++) {
           
            rightSum -= nums[i]; 
            
            int val = nums[i];
          
            nums[i] = abs(leftSum - rightSum); 
            
            
            leftSum += val; 
        }
        return nums;
    }
};