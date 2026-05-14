/*
 * Problem: Check if Array is Good (LeetCode 2784)
 * Concept: Arrays / Frequency Array (Hashing)
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<int> count(n + 1, 0);
        
        for(int num : nums) {
            
            if(num > n) return false;
            count[num]++;
        }
        
       
        for(int i = 1; i < n; i++) {
            if(count[i] != 1) return false;
        }
        
        
        return count[n] == 2;
    }
};