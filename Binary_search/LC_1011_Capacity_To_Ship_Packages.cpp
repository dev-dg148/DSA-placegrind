/*
 * Problem: Capacity To Ship Packages Within D Days (LeetCode 1011)
 * Concept: Binary Search on Answer
 * Time Complexity: O(N * log(Sum - Max))
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkships(const vector<int>& weights, int days, int mid) {
        int splits = 1, sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (weights[i] + sum > mid) {
                splits++;
                sum = weights[i];
            } else {
                sum += weights[i];
            }
        }
        return splits <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, h = 0, ans = 0;
        for (int i = 0; i < weights.size(); i++) {
            l = max(l, weights[i]);
            h += weights[i];
        }
        
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (checkships(weights, days, mid)) {
                ans = mid;
                h = mid - 1; 
            } else {
                l = mid + 1; 
            }
        }
        return ans;
    }
};