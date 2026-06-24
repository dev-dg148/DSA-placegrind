/*
 * Problem: Single Number (LeetCode 136)
 * Concept: Bit Manipulation (XOR)
 * TC: $O(N)$ - Where N is the size of the array, traversing it only once.
 * SC: $O(1)$ - Constant space, no extra memory used.
 */

#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            // XOR all elements. Duplicates cancel out to 0.
            ans ^= nums[i]; 
        }
        return ans;
    }
};