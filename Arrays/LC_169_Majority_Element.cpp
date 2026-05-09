/*
 * Problem: Majority Element (LeetCode 169)
 * Concept: Arrays / Moore's Voting Algorithm
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote = 0;
        int cand = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (vote == 0) {
                cand = nums[i];
            }
            if (nums[i] == cand) {
                vote++;
            } else {
                vote--;
            }
        }
        return cand;
    }
};