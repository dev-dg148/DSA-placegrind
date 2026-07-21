/*
 * Problem: Self Dividing Numbers (LeetCode 728)
 * Concept: Math & Digit Extraction
 * TC: $O(N \times D)$ - N is range (r - l), D is digits in max number.
 * SC: $O(1)$ - Constant space (excluding the output array).
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int l, int r) {
        vector<int> ans;
        for (int i = l; i <= r; i++) {
            int d = i;
            while (d > 0) {
                int rem = d % 10;
                if (rem != 0 && i % rem == 0) {
                    d /= 10;
            
                } else {
                    break;
                }
            }
            if (d == 0) ans.push_back(i);
        }
        return ans;
    }
};