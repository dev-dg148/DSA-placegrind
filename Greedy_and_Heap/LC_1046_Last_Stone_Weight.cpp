/*
 * Problem: Last Stone Weight (LeetCode 1046)
 * Concept: Vector Operations & Sorting (Brute Force)
 * Time Complexity: O(N^2 * log N) - Vector is re-sorted inside the loop
 * Space Complexity: O(1) - In-place operations on the input vector
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       
        sort(stones.begin(), stones.end());
        
       
        while (stones.size() > 1) {
           
            if (stones.back() == stones[stones.size() - 2]) {
                stones.pop_back();
                stones.pop_back();
            } 
           
            else {
                stones[stones.size() - 2] = stones.back() - stones[stones.size() - 2];
                stones.pop_back();
                
                sort(stones.begin(), stones.end());
            }
        }
        
       
        return (stones.empty()) ? 0 : stones[0];
    }
};