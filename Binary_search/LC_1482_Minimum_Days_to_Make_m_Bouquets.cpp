/*
 * Problem: Minimum Number of Days to Make m Bouquets (LeetCode 1482)
 * Concept: Binary Search on Answers
 * Time Complexity: O(N * log(Max_Day))
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkdays(vector<int>& bloomDay, int k, int mid, int m) {
        int conseq = 0;
        int bouquets = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                conseq++;
                if (conseq == k) {
                    bouquets++;
                    if (bouquets == m) {
                        return true;
                    }
                    conseq = 0;
                }
            } else {
                conseq = 0;
            }
        }
        return false;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans = -1;
        if (bloomDay.size() < (long long)m * k) {
            return ans;
        }
        int l = 1, h = *max_element(bloomDay.begin(), bloomDay.end());

        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (checkdays(bloomDay, k, mid, m)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};