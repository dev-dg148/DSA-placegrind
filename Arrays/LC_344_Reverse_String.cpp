/*
 * Problem: Reverse String (LeetCode 344)
 * Concept: Two Pointers
 * TC: $O(N)$ - Where N is the number of characters in the string, traversing only up to the middle.
 * SC: $O(1)$ - Constant space, performing swap operation in-place.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right) {
            // Swap elements using two pointers
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};