/*
 * Problem: Can Make Arithmetic Progression From Sequence (LeetCode 1502)
 * Concept: Sorting & Arrays
 * TC: $O(N \log N)$ - Time taken to sort the array before checking differences.
 * SC: $O(1)$ - Constant space, no extra memory used as sorting is done in-place.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int diff = arr[1] - arr[0];
        
        for(int i = 2; i < arr.size(); i++) {
            if(arr[i] - arr[i-1] != diff) {
                return false; 
            }
        }
        
        return true; 
    }
};